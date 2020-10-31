#!/bin/sh

if [[ -f /usr/local/cuda/bin/nvcc ]] ; then
  /usr/local/cuda/bin/nvcc  --output-file nvidia-smi ./nvidia-smi.cpp
else
  nvcc --output-file nvidia-smi ./nvidia-smi.cpp
fi


./nvidia-smi
