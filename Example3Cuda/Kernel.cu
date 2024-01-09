#include "Kernel.cuh"
#include "cuda.h"
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
//#include "device_functions.h"
__global__ void kernel(unsigned* src, int width, int height, double a, double b) {
	int x = blockIdx.x * blockDim.x + threadIdx.x;
	int y = blockIdx.y * blockDim.y + threadIdx.y;

	if ((x < width) && (y < height))
	{
		unsigned pixel = src[y * width + x];
		unsigned red = (pixel & 0x00FF0000) >> 0x10;
		unsigned green = (pixel & 0x0000FF00) >> 0x8;
		unsigned blue = pixel & 0x000000FF;

		unsigned enhancedRed = (a * red + b);
		if (enhancedRed > 255)
			enhancedRed = 255;
		unsigned enhancedGreen = (a * green + b);
		if (enhancedGreen > 255)
			enhancedGreen = 255;
		unsigned enhancedBlue = (a * blue + b);
		if (enhancedBlue > 255)
			enhancedBlue = 255;

		src[y * width + x] = 0xFF000000 | (enhancedRed << 0x10) |
			(enhancedGreen << 0x8) | enhancedBlue;
	}
}

int calc(unsigned* srcImage, int width, int height, double a, double b)
{

	unsigned* dev_srcImage;
	size_t size = sizeof(unsigned) * width * height;
	if (cudaMalloc((void**)&dev_srcImage, size) !=
		cudaError::cudaSuccess) return -1;
	if (cudaMemcpy(dev_srcImage, srcImage, size,
		cudaMemcpyHostToDevice) != cudaError::cudaSuccess)
		return -1;
	// ћаксимальное количество нитей на блок может
		dim3 threads(128, 128);
	dim3 blocks((width + threads.x - 1) / threads.x,
		(height + threads.y - 1) / threads.y);
	kernel << <threads, blocks >> > (dev_srcImage, width, height, a, b);
	cudaError error = cudaMemcpy(srcImage, dev_srcImage,
		size,
		cudaMemcpyDeviceToHost);
	if (error != cudaError::cudaSuccess) return -1;
	cudaFree(dev_srcImage);
	return 0;
}