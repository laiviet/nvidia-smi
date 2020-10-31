#!/bin/sh
/usr/local/cuda/bin/nvcc  --output-file nvidia-smi ./nvidia-smi.cpp

./nvidia-smi
