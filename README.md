# nvidia-smi
Alternative ``nvidia-smi`` for Mac. Since ``NVML`` is not supported on OSX, GPU usage and power comsumption are not available in this tool.

## Requirements

You should have your CUDA driver and CUDA toolkit installed. 


## Compile

Just as easy as follow.

```
./compile.sh
```


## Run

```
nvidia-smi
```

## Test

Tested on:

```
CPU: Intel Core i7 4700K
GPU: Nvidia GTX 1080 Ti
MacOS: High Sierra (10.13.6)
CUDA: 10.1
```

## Sample output

```
+------------------------------------------------------+
| NVIDIA-SMI-OSX 1.0              CUDA Version: 10.1   |
|-------------------------------+----------------------+
| GPU Name                      |         Memory-Usage |
|     Compute Cap.              |                      |
|===============================+======================+
|   0 GeForce GTX 1080 Ti       |  5092 MiB / 11263MiB |
|     6.1                       |                      |
|-------------------------------+----------------------+
```


## Tips

If you want to see GPU usage, MacOS 's Activity Monitor has a visualization of GPU usage. 

```Open Activity Monitor -> Window -> GPU History```

Or

```Open Activity Monitor -> Command + 4```

![GPU usage](https://github.com/laiviet/nvidia-smi/blob/main/gpu_usage.png)
