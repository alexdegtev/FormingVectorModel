#include "DefaultImage.hpp"

FVM::Core::Objects::Image::DefaultImage::DefaultImage() : DefaultImage(0, 0)
{
}

FVM::Core::Objects::Image::DefaultImage::DefaultImage(int rows, int cols) : rows_(rows), cols_(cols)
{
	data = new Pixel[rows_ * cols_];
}

FVM::Core::Objects::Image::DefaultImage::DefaultImage(const DefaultImage& other) : rows_(other.rows_), cols_(other.cols_)
{
	data = new Pixel[rows_ * cols_];
	for (int i = 0; i < rows_ * cols_; i++)
		data[i] = other.data[i];
}

FVM::Core::Objects::Image::DefaultImage::DefaultImage(const DefaultImage* other) : rows_(other->rows_), cols_(other->cols_)
{
	data = new Pixel[rows_ * cols_];
	for (int i = 0; i < rows_ * cols_; i++)
		data[i] = other->data[i];
}

FVM::Core::Objects::Image::DefaultImage::~DefaultImage()
{
	if (data)
		delete[] data;
}

FVM::Core::Objects::Image::Pixel* FVM::Core::Objects::Image::DefaultImage::pixel(int row, int col)
{
	if(row < 0 || row >= rows_ || col < 0 || col >= cols_) return nullptr;
	return &data[row * cols_ + col];
}

void FVM::Core::Objects::Image::DefaultImage::pixel(int row, int col, Pixel* pixel)
{
	if (row < 0 || row >= rows_ || col < 0 || col >= cols_) return;
	data[row * cols_ + col] = pixel == nullptr ? Pixel() : *pixel;
}

int FVM::Core::Objects::Image::DefaultImage::rows()
{
	return rows_;
}

int FVM::Core::Objects::Image::DefaultImage::cols()
{
	return cols_;
}

void FVM::Core::Objects::Image::DefaultImage::transform(Transformations::ITransformation* transformation)
{
	transformation->execute(this);
	delete transformation;
}

FVM::Core::Objects::Image::IImage* FVM::Core::Objects::Image::DefaultImage::copy()
{
	return new DefaultImage(this);
}
