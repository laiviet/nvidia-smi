#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <cuda_runtime_api.h>
// #include <nvml.h>
using namespace std;

#define CUDA_CALL(function, ...)  { \
    cudaError_t status = function(__VA_ARGS__); \
    anyCheck(status == cudaSuccess, cudaGetErrorString(status), #function, __FILE__, __LINE__); \
}

void anyCheck(bool is_ok, const char *description, const char *function, const char *file, int line) {
    if (!is_ok) {
        std::cout << "Error: " << description << " in " << function << " at " << file << ":" << line << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main() {
    int cudaDeviceCount;
    struct cudaDeviceProp deviceProp;
    size_t memFree, memTotal, memUsed;
    int driverVersion;
    float driverVerionFloat;

    CUDA_CALL(cudaGetDeviceCount, &cudaDeviceCount);
    CUDA_CALL(cudaDriverGetVersion, &driverVersion);
    driverVerionFloat = driverVersion/1000+ (driverVersion%1000/10/10.0);
    cout<<"+------------------------------------------------------+"<<endl;
    cout<<"| NVIDIA-SMI-OSX 1.0              CUDA Version: "<<setw(6)<<left<<driverVerionFloat<<" |"<<endl;
    cout<<"|-------------------------------+----------------------+"<<endl;
    cout<<"| GPU Name                      |         Memory-Usage |"<<endl;
    cout<<"|     Compute Cap.              |                      |"<<endl;
    cout<<"|===============================+======================+"<<endl;

    for (int deviceId = 0; deviceId < cudaDeviceCount; ++deviceId) {
        CUDA_CALL(cudaSetDevice, deviceId);
        CUDA_CALL(cudaGetDeviceProperties, &deviceProp, deviceId);

        //std::cout.imbue(std::locale("en_US.utf8"));
        cout << "| "<< setw(3)<<right<< deviceId << " ";
        cout << setw(25) <<left<< deviceProp.name << " | ";

        CUDA_CALL(cudaMemGetInfo, &memFree, &memTotal);

        memTotal = memTotal/1024/1024;
        memUsed = memTotal - memFree/1024/1024;
        cout <<" "<< setw(5) << memUsed << "MiB / " <<setw(5) << memTotal<<"MiB |"<<endl;
        cout <<"|     " <<deviceProp.major << "." << deviceProp.minor<<"                       |                      |"<<endl;
        cout <<"|-------------------------------+----------------------+"<<endl;

    }
    return 0;
}
