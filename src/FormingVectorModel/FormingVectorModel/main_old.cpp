//#include <iostream>
//#include "opencv2/opencv.hpp"
//#include <iterator>
//
//
//template<class pixel_type>
//class IImage;
//
//
//class Functions
//{
//public:
//	static unsigned char rgb_to_brightness(unsigned char red, unsigned char green, unsigned char blue)
//	{
//		return static_cast<unsigned char>(round(
//			0.299 * static_cast<double>(red) +
//			0.587 * static_cast<double>(green) +
//			0.114 * static_cast<double>(blue)
//		));	// From YIQ model.
//	}
//
//	template<typename image_pixel_type>
//	static void iimage_to_mat(IImage<image_pixel_type> *image, cv::Mat* mat)
//	{
//		for (int i = 0; i < image->rows(); i++)
//		{
//			for (int j = 0; j < image->cols(); j++)
//			{
//				if (mat->channels() == 1)
//				{
//					mat->at<uchar>(i, j) = image->get(i, j)->brightness();
//				}
//				else
//				{
//					image_pixel_type pixel(image->get(i, j));
//					mat->at<cv::Vec3b>(i, j) = cv::Vec3b(pixel.blue(), pixel.green(), pixel.red());
//				}
//			}
//		}
//	}
//
//	template<typename image_type, typename pixel_type>
//	static void mat_to_iimage(cv::Mat* mat, image_type* image)
//	{
//		for (int i = 0; i < mat->rows; i++)
//		{
//			for (int j = 0; j < mat->cols; j++)
//			{
//				if (mat->channels() == 1)
//				{
//					pixel_type pixel(i, j, mat->at<uchar>(i, j));
//					image->set(i, j, &pixel);
//				}
//				else
//				{
//					cv::Vec3b pixel = mat->at<cv::Vec3b>(i, j);
//					pixel_type new_pixel(i, j, pixel.val[2], pixel.val[1], pixel.val[0]);
//					image->set(i, j, &new_pixel);
//				}
//			}
//		}
//	}
//};
//
//class IObject
//{
//public:
//	virtual ~IObject() { }
//};
//
//class IPoint : public IObject
//{
//public:
//	virtual ~IPoint() { }
//
//	virtual int x() = 0;
//	virtual int y() = 0;
//};
//
//class Point : public IPoint
//{
//public:
//	Point() : Point(0, 0) {}
//	Point(int x, int y) : _x(x), _y(y) {}
//	Point(const Point& other) : _x(other._x), _y(other._y) {}
//
//	int x() override { return _x; }
//	int y() override { return _y; }
//
//private:
//	int _x;
//	int _y;
//};
//
//template<class point_type>
//class ILine : public IObject
//{
//public:
//	virtual ~ILine() { }
//
//	virtual IPoint *begin() = 0;
//	virtual IPoint *end() = 0;
//};
//
//template<class point_type>
//class Line : public ILine<point_type>
//{
//public:
//	Line() : Line(nullptr, nullptr) {}
//	Line(IPoint *begin, IPoint *end) : _begin(begin), _end(end)
//	{
//		if (!_begin)
//			_begin = new point_type();
//
//		if (!_end)
//			_end = new point_type();
//	}
//	~Line()
//	{
//		if (_begin)
//			delete _begin;
//
//		if (_end)
//			delete _end;
//	}
//
//	IPoint* begin() override { return _begin; }
//	IPoint* end() override { return _end; }
//
//private:
//	IPoint* _begin;
//	IPoint* _end;
//};
//
//class IColor
//{
//public:
//	virtual ~IColor() {}
//
//	virtual unsigned char red() = 0;
//	virtual void red(unsigned char value) = 0;
//
//	virtual unsigned char green() = 0;
//	virtual void green(unsigned char value) = 0;
//
//	virtual unsigned char blue() = 0;
//	virtual void blue(unsigned char value) = 0;
//
//	virtual unsigned char brightness() = 0;
//	virtual void brightness(unsigned char value) = 0;
//};
//
//class Color : public IColor
//{
//public:
//	Color() : Color((unsigned char)0) {}
//	Color(unsigned char brightness) : Color(brightness, brightness, brightness) {}
//	Color(IColor *c) : Color(c->red(), c->green(), c->blue()) {}
//	Color(unsigned char red, unsigned char green, unsigned char blue) : _red(red), _green(green), _blue(blue) {}
//
//	unsigned char red() override { return _red; }
//	void red(unsigned char value) override { _red = value; }
//
//	unsigned char green() override { return _green; }
//	void green(unsigned char value) override { _green = value; }
//
//	unsigned char blue() override { return _blue; }
//	void blue(unsigned char value) override { _blue = value; }
//
//	unsigned char brightness() override { return Functions::rgb_to_brightness(_red, _green, _blue); }
//	void brightness(unsigned char value) override { _red = _green = _blue = value; }
//
//private:
//	unsigned char _red;
//	unsigned char _green;
//	unsigned char _blue;
//};
//
//template<class point_type, class color_type>
//class IPixel : public IPoint, public IColor
//{
//public:
//	enum Type
//	{
//		turn_on = 255,	// the pixels of interest (object)
//		turn_off = 0	// background
//	};
//
//	virtual ~IPixel() { }
//};
//
//template<class point_type, class color_type>
//class Pixel : public IPixel<point_type, color_type>
//{
//public:
//	Pixel() : Pixel(nullptr, nullptr) { }
//	Pixel(IPoint *point, IColor *color) : _point(point), _color(color)
//	{
//		if (!_point)
//			_point = new point_type;
//
//		if (!_color)
//			_color = new color_type;
//	}
//	Pixel(int x, int y, unsigned char red, unsigned char green, unsigned char blue) : Pixel(new point_type(x, y), new color_type(red, green, blue)) { }
//	Pixel(unsigned char red, unsigned char green, unsigned char blue) : Pixel(0, 0, red, green, blue) { }
//	Pixel(int x, int y, unsigned char brightness) : Pixel(new point_type(x, y), new color_type(brightness)) { }
//	~Pixel()
//	{
//		if (_point)
//			delete _point;
//
//		if (_color)
//			delete _color;
//	}
//
//	int x() override
//	{
//		return _point->x();
//	}
//	int y() override
//	{
//		return _point->y();
//	}
//
//	unsigned char red() override
//	{
//		return _color->red();
//	}
//	void red(unsigned char value) override
//	{
//		_color->red(value);
//	}
//
//	unsigned char green() override
//	{
//		return _color->green();
//	}
//	void green(unsigned char value) override
//	{
//		_color->green(value);
//	}
//
//	unsigned char blue() override
//	{
//		return _color->blue();
//	}
//	void blue(unsigned char value) override
//	{
//		_color->blue(value);
//	}
//
//	unsigned char brightness() override
//	{
//		return _color->brightness();
//	}
//	void brightness(unsigned char value) override
//	{
//		_color->brightness(value);
//	}
//
//private:
//	IPoint *_point;
//	IColor *_color;
//};
//
//template<class T>
//class IMatrix
//{
//public:
//	virtual ~IMatrix() {}
//	virtual size_t rows() = 0;
//	virtual size_t cols() = 0;
//	virtual T *get(size_t row, size_t col) = 0;
//	virtual void set(size_t row, size_t col, T *value) = 0;
//};
//
//template<class T>
//class Matrix : public IMatrix<T>
//{
//public:
//	Matrix() : Matrix(0, 0) {}
//	Matrix(size_t rows, size_t cols) : _rows(rows), _cols(cols)
//	{
//		_data = new T[_rows * _cols];
//	}
//	~Matrix()
//	{
//		if (_data)
//			delete[] _data;
//	}
//
//	size_t rows() override { return _rows; }
//	size_t cols() override { return _cols; }
//	T *get(size_t row, size_t col) override
//	{
//		if (row < _rows && col < _cols)
//			return &_data[row * _cols + col];
//		else
//			throw "index out of range";
//	}
//	void set(size_t row, size_t col, T *value) override
//	{
//		if (row < _rows && col < _cols)
//			_data[row * _cols + col] = *value;
//		else
//			throw "index out of range";
//	}
//
//private:
//	T *_data;
//	size_t _rows;
//	size_t _cols;
//};
//
//template<class image_type, class pixel_type>
//class ITransformation
//{
//public:
//	virtual ~ITransformation() { }
//
//	virtual void execute(image_type *image) = 0;
//};
//
//template<class image_type, class pixel_type>
//class IVectorization
//{
//public:
//	virtual ~IVectorization() { }
//
//	virtual std::vector<IObject*> execute(image_type *image) = 0;
//};
//
//template<class pixel_type>
//class IImage : public IMatrix<IPixel<IPoint, IColor>>
//{
//public:
//	virtual ~IImage() {}
//
//	virtual void transform(ITransformation<IImage<pixel_type>, pixel_type> *transforamtion) = 0;
//	virtual std::vector<IObject*> vectorize(IVectorization<IImage<pixel_type>, pixel_type> *vectorization) = 0;
//};
//
//template<class pixel_type>
//class Image : public IImage<pixel_type>
//{
//public:
//	Image() : Image(0, 0) {}
//	Image(size_t rows, size_t cols) : _data(new Matrix<pixel_type>(rows, cols)) {}
//	~Image()
//	{
//		if (_data)
//			delete _data;
//	}
//	size_t rows() override { return _data->rows(); }
//	size_t cols() override { return _data->cols(); }
//	IPixel<IPoint, IColor>* get(size_t row, size_t col) override { return _data->get(row, col); }
//	void set(size_t row, size_t col, IPixel<IPoint, IColor>* value) override { _data->set(row, col, (pixel_type*)value); }
//
//	void transform(ITransformation<IImage<pixel_type>, pixel_type>* transforamtion) override { transforamtion->execute(this); }
//	std::vector<IObject*> vectorize(IVectorization<IImage<pixel_type>, pixel_type>* vectorization) override { return vectorization->execute(this); }
//
//private:
//	IMatrix<pixel_type> *_data;
//};
//
//class Path
//{
//public:
//	Path(std::string full_path)
//	{
//		int position;
//		for (position = full_path.size() - 1; full_path[position] != '.'; position--)
//		{
//			_file_extention += full_path[position];
//		}
//		std::reverse(_file_extention.begin(), _file_extention.end());
//
//		if (_file_extention.empty())
//		{
//			position = full_path.size() - 1;
//		}
//		else
//		{
//			position--;
//		}
//
//		for (; full_path[position] != '/' && full_path[position] != '\\'; position--)
//		{
//			_file_name += full_path[position];
//		}
//		std::reverse(_file_name.begin(), _file_name.end());
//
//		position--;
//
//		for (; position >= 0; position--)
//		{
//			_path_to_file += full_path[position];
//		}
//		std::reverse(_path_to_file.begin(), _path_to_file.end());
//	}
//	Path(std::string path_to_file, std::string file_name, std::string file_extention) : _path_to_file(path_to_file), _file_name(file_name), _file_extention(file_extention) {}
//
//	std::string path() const { return _path_to_file; }
//	std::string name() const { return _file_name; }
//	std::string extention() const { return _file_extention; }
//	std::string full() const { return _path_to_file + _separator + _file_name + '.' + _file_extention; }
//
//private:
//	std::string _path_to_file;
//	std::string _file_name;
//	std::string _file_extention;
//
//#ifdef _WIN32
//	char _separator = '\\';
//#elif _unix_
//	char _separator = '/';
//#endif
//};
//
//class Reader
//{
//public:
//	template<typename image_type, typename pixel_type>
//	static IImage<pixel_type> *read(std::string path_to_file)
//	{
//		cv::Mat mat = cv::imread(path_to_file);
//		IImage<pixel_type> *image = new image_type(mat.rows, mat.cols);
//		cv::Vec3b row_color;
//
//		for (int i = 0; i < mat.rows; i++)
//		{
//			for (int j = 0; j < mat.cols; j++)
//			{
//				row_color = mat.at<cv::Vec3b>(i, j);
//				pixel_type pixel(i, j, row_color.val[2], row_color.val[1], row_color.val[0]);
//				image->set(i, j, &pixel);
//			}
//		}
//
//		return image;
//	}
//
//	template<typename image_type, typename pixel_type>
//	static IImage<pixel_type> *read(Path path)
//	{
//		return read<image_type, pixel_type>(path.full());
//	}
//};
//
//class Writer
//{
//public:
//	template<typename pixel_type>
//	static void write(IImage<pixel_type> *image, std::string path_to_file)
//	{
//		cv::Mat mat(image->rows(), image->cols(), CV_8UC3);
//
//		for (int i = 0; i < image->rows(); i++)
//		{
//			for (int j = 0; j < image->cols(); j++)
//			{
//				pixel_type pixel(image->get(i, j));
//				mat.at<cv::Vec3b>(i, j) = cv::Vec3b(pixel.blue(), pixel.green(), pixel.red());
//			}
//		}
//
//		cv::imwrite(path_to_file, mat);
//	}
//
//	template<typename pixel_type>
//	static void write(IImage<pixel_type> *image, Path path)
//	{
//		write(image, path.full());
//	}
//};
//
//template<class image_type, class pixel_type>
//class IGrayscalation : public ITransformation<image_type, pixel_type>
//{
//public:
//	virtual ~IGrayscalation() { }
//};
//
//template<class image_type, class pixel_type>
//class YIQGrayscalation : public IGrayscalation<image_type, pixel_type>
//{
//	void execute(image_type* image) override
//	{
//		for (int i = 0; i < image->rows(); i++)
//		{
//			for (int j = 0; j < image->cols(); j++)
//			{
//				//pixel_type pixel(image->get(i, j)->brightness());
//				//image->set(i, j, &pixel);
//			}
//		}
//	}
//};
//
//template<class image_type, class pixel_type>
//class IBinarization : public ITransformation<image_type, pixel_type>
//{
//public:
//	virtual ~IBinarization() { }
//};
//
//template<class image_type, class pixel_type>
//class OtsuBinarization : public IBinarization<image_type, pixel_type>
//{
//public:
//	void execute(image_type* image) override
//	{
//		unsigned char t = threshold(image);
//
//		for (int i = 0; i < image->rows(); i++)
//		{
//			for (int j = 0; j < image->cols(); j++)
//			{
//				pixel_type pixel(image->get(i, j));
//				pixel.brightness(t > pixel.brightness() ? pixel_type::Type::turn_on : pixel_type::Type::turn_off);
//				image->set(i, j, &pixel);
//			}
//		}
//	}
//
//private:
//	unsigned char threshold(image_type* image)
//	{
//		//TODO: Добавить реализацию
//		throw "method is not implemented";
//	}
//};
//
//template<class image_type, class pixel_type>
//class MiddleThresholdBinarization : public IBinarization<image_type, pixel_type>
//{
//public:
//	void execute(image_type* image) override
//	{
//		unsigned char t = 128;
//
//		for (int i = 0; i < image->rows(); i++)
//		{
//			for (int j = 0; j < image->cols(); j++)
//			{
//				pixel_type pixel(image->get(i, j));
//				pixel.brightness(t > pixel.brightness() ? pixel_type::Type::turn_on : pixel_type::Type::turn_off);
//				image->set(i, j, &pixel);
//			}
//		}
//	}
//};
//
//template<class image_type, class pixel_type>
//class ISkeletization : public ITransformation<image_type, pixel_type>
//{
//public:
//	virtual ~ISkeletization() { }
//};
//
///**
//* Code for thinning a binary image using Zhang-Suen algorithm.
//* http://opencv-code.com/quick-tips/implementation-of-thinning-algorithm-in-opencv/
//*/
//template<class image_type, class pixel_type>
//class ZhangSuenSkeletization : public ISkeletization<image_type, pixel_type>
//{
//public:
//	void execute(image_type* image) override
//	{
//		cv::Mat skeleton(image->rows(), image->cols(), CV_8UC1);
//		Functions::iimage_to_mat<pixel_type>(image, &skeleton);
//
//		thinning(skeleton);
//
//		Functions::mat_to_iimage<image_type, pixel_type>(&skeleton, image);
//	}
//
//private:
//	void thinning(cv::Mat& im)
//	{
//		im /= 255;
//
//		cv::Mat prev = cv::Mat::zeros(im.size(), CV_8UC1);
//		cv::Mat diff;
//
//		do {
//			thinning_iteration(im, 0);
//			thinning_iteration(im, 1);
//			cv::absdiff(im, prev, diff);
//			im.copyTo(prev);
//		} while (cv::countNonZero(diff) > 0);
//
//		im *= 255;
//	}
//
//	void thinning_iteration(cv::Mat& im, int iter)
//	{
//		cv::Mat marker = cv::Mat::zeros(im.size(), CV_8UC1);
//
//		for (int i = 1; i < im.rows - 1; i++)
//		{
//			for (int j = 1; j < im.cols - 1; j++)
//			{
//				uchar p2 = im.at<uchar>(i - 1, j);
//				uchar p3 = im.at<uchar>(i - 1, j + 1);
//				uchar p4 = im.at<uchar>(i, j + 1);
//				uchar p5 = im.at<uchar>(i + 1, j + 1);
//				uchar p6 = im.at<uchar>(i + 1, j);
//				uchar p7 = im.at<uchar>(i + 1, j - 1);
//				uchar p8 = im.at<uchar>(i, j - 1);
//				uchar p9 = im.at<uchar>(i - 1, j - 1);
//
//				int A = (p2 == 0 && p3 == 1) + (p3 == 0 && p4 == 1) +
//					(p4 == 0 && p5 == 1) + (p5 == 0 && p6 == 1) +
//					(p6 == 0 && p7 == 1) + (p7 == 0 && p8 == 1) +
//					(p8 == 0 && p9 == 1) + (p9 == 0 && p2 == 1);
//				int B = p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9;
//				int m1 = iter == 0 ? (p2 * p4 * p6) : (p2 * p4 * p8);
//				int m2 = iter == 0 ? (p4 * p6 * p8) : (p2 * p6 * p8);
//
//				if (A == 1 && (B >= 2 && B <= 6) && m1 == 0 && m2 == 0)
//					marker.at<uchar>(i, j) = 1;
//			}
//		}
//
//		im &= ~marker;
//	}
//};
//
///**
//* Code for thinning a binary image using Guo-Hall algorithm.
//* http://opencv-code.com/quick-tips/implementation-of-guo-hall-thinning-algorithm/
//*/
//template<class image_type, class pixel_type>
//class GuoHallSkeletization : public ISkeletization<image_type, pixel_type>
//{
//public:
//	void execute(image_type* image) override
//	{
//		cv::Mat skeleton(image->rows(), image->cols(), CV_8UC1);
//		Functions::iimage_to_mat<pixel_type>(image, &skeleton);
//
//		thinning(skeleton);
//
//		Functions::mat_to_iimage<image_type, pixel_type>(&skeleton, image);
//	}
//
//private:
//	void thinning(cv::Mat& im)
//	{
//		im /= 255;
//
//		cv::Mat prev = cv::Mat::zeros(im.size(), CV_8UC1);
//		cv::Mat diff;
//
//		do {
//			thinning_iteration(im, 0);
//			thinning_iteration(im, 1);
//			cv::absdiff(im, prev, diff);
//			im.copyTo(prev);
//		} while (cv::countNonZero(diff) > 0);
//
//		im *= 255;
//	}
//
//	void thinning_iteration(cv::Mat& im, int iter)
//	{
//		cv::Mat marker = cv::Mat::zeros(im.size(), CV_8UC1);
//
//		for (int i = 1; i < im.rows - 1; i++)
//		{
//			for (int j = 1; j < im.cols - 1; j++)
//			{
//				uchar p2 = im.at<uchar>(i - 1, j);
//				uchar p3 = im.at<uchar>(i - 1, j + 1);
//				uchar p4 = im.at<uchar>(i, j + 1);
//				uchar p5 = im.at<uchar>(i + 1, j + 1);
//				uchar p6 = im.at<uchar>(i + 1, j);
//				uchar p7 = im.at<uchar>(i + 1, j - 1);
//				uchar p8 = im.at<uchar>(i, j - 1);
//				uchar p9 = im.at<uchar>(i - 1, j - 1);
//
//				int C = (!p2 & (p3 | p4)) + (!p4 & (p5 | p6)) +
//					(!p6 & (p7 | p8)) + (!p8 & (p9 | p2));
//				int N1 = (p9 | p2) + (p3 | p4) + (p5 | p6) + (p7 | p8);
//				int N2 = (p2 | p3) + (p4 | p5) + (p6 | p7) + (p8 | p9);
//				int N = N1 < N2 ? N1 : N2;
//				int m = iter == 0 ? ((p6 | p7 | !p9) & p8) : ((p2 | p3 | !p5) & p4);
//
//				if (C == 1 && (N >= 2 && N <= 3) & m == 0)
//					marker.at<uchar>(i, j) = 1;
//			}
//		}
//
//		im &= ~marker;
//	}
//};
//
//class ColorWithState : public IColor
//{
//public:
//	enum State
//	{
//		unvisited,
//		visited,
//		excluded
//	};
//
//	unsigned char red() override { return _color->red(); }
//	void red(unsigned char value) override { _color->red(value); }
//	unsigned char green() override { return _color->green(); }
//	void green(unsigned char value) override;
//	unsigned char blue() override;
//	void blue(unsigned char value) override;
//	unsigned char brightness() override;
//	void brightness(unsigned char value) override;
//
//	State state() { return _state; }
//	void state(State value) { _state = value; }
//
//private:
//	State _state;
//	IColor *_color;
//};
//
////class PixelWithState : public IPixel
////{
////public:
////	enum State
////	{
////		unvisited,
////		visited,
////		excluded
////	};
////
////	PixelWithState() : _state(State::unvisited), _brightness(0) {}
////
////	int x() override { return 0; }
////	int y() override { return 0; }
////	unsigned char red() override { return 0; }
////	void red(unsigned char value) override {}
////	unsigned char green() override { return 0; }
////	void green(unsigned char value) override {}
////	unsigned char blue() override { return 0; }
////	void blue(unsigned char value) override {}
////	unsigned char brightness() override { return _brightness; }
////	void brightness(unsigned char value) override { _brightness = value; }
////
////	State state() const { return _state; }
////	void state(State value) { _state = value; }
////
////private:
////	State _state;
////	unsigned char _brightness;
////};
//
////class VectorizationState
////{
////public:
////	VectorizationState() : _current(nullptr), _previous(nullptr), _start(nullptr) {}
////
////	IPixel *current() const { return _current; }
////	void current(IPixel *value) { _current = value; }
////	IPixel *previous() const { return _previous; }
////	void previous(IPixel *value) { _previous = value; }
////	IPixel *start() const { return _start; }
////	void start(IPixel *value) { _start = value; }
////	std::vector<IPixel*> neighbours() const { return _neighbours; }
////	void neighbours(std::vector<IPixel*> value) { _neighbours = value; }
////	std::vector<IPixel*> next()
////	{
////		std::vector<IPixel*> result;
////		for(auto i : _neighbours)
////		{
////			if(i != _previous /*&& i.isNotVisited*/)
////			{
////				result.push_back(i);
////			}
////		}
////		return result;
////	}
////
////private:
////	IPixel *_current;
////	IPixel *_previous;
////	IPixel *_start;
////	std::vector<IPixel*> _neighbours;
////};
//
////template<typename pixel_type>
////class ImageWithVisitMarks: public IImage<pixel_type>
////{
////public:
////	size_t rows() override;
////	size_t cols() override;
////	IColor* get(size_t row, size_t col) override;
////	void set(size_t row, size_t col, IColor* value) override;
////	void transform(ITransformation<IImage<pixel_type>, pixel_type>* transforamtion) override;
////	std::vector<IObject*> vectorize(IVectorization<IImage<pixel_type>, pixel_type>* vectorization) override;
////
////private:
////
////};
//
//template<typename image_type, typename pixel_type>
//class Vectorization : public IVectorization<image_type, pixel_type>
//{
//public:
//	std::vector<IObject*> execute(image_type* image) override
//	{
//		std::vector<IObject*> objects;
//		return objects;
//	}
//};
//
//
//int main1(int argc, char *argv[])
//{
//	//std::cout << "params:" << std::endl;
//	//for (int i = 0; i < argc; i++)
//	//{
//	//	std::cout << '\t' << "[" << i << "]: " << argv[i] << std::endl;
//	//}
//
//	switch (argc)
//	{
//	case 2:
//		if (strcmp(argv[1], "help") == 0)
//		{
//			std::cout << "<program_name> <image_name>" << std::endl;
//		}
//		else
//		{
//			std::cout << "starting..." << std::endl;
//
//			Path path(argv[1]);
//			std::cout << "reading..." << std::endl;
//			//IImage<Color> *image = Reader::read<Image<Color>, Color>(path);
//			IImage<Pixel<Point, Color>> *image = Reader::read<Image<Pixel<Point, Color>>, Pixel<Point, Color>>(path);
//
//			std::cout << "image:" << std::endl;
//			std::cout << '\t' << "rows (height): " << image->rows() << std::endl;
//			std::cout << '\t' << "cols (width): " << image->cols() << std::endl;
//
//			std::cout << "grayscalation..." << std::endl;
//			image->transform(new YIQGrayscalation<IImage<Pixel<Point, Color>>, Pixel<Point, Color>>);
//			std::cout << "writing..." << std::endl;
//			Writer::write(image, Path(path.path(), path.name() + "_out1", path.extention()));
//
//			//std::cout << "binarization..." << std::endl;
//			//image->transform(new MiddleThresholdBinarization<IImage<Color>, Color>);
//			//std::cout << "writing..." << std::endl;
//			//Writer::write(image, Path(path.path(), path.name() + "_out2", path.extention()));
//
//			/*std::cout << "skeletization (ZhangSuenSkeletization)..." << std::endl;
//			image->transform(new ZhangSuenSkeletization<IImage<Color>, Color>);
//			std::cout << "writing..." << std::endl;
//			Writer::write(image, Path(path.path(), path.name() + "_out3", path.extention()));*/
//
//			//std::cout << "skeletization (GuoHallSkeletization)..." << std::endl;
//			//image->transform(new GuoHallSkeletization<IImage<Color>, Color>);
//			//std::cout << "writing..." << std::endl;
//			//Writer::write(image, Path(path.path(), path.name() + "_out4", path.extention()));
//
//			std::cout << "end." << std::endl;
//		}
//
//		break;
//
//	case 3:
//		if (strcmp(argv[1], "/debug") == 0)
//		{
//			Path path(argv[2]);
//			path = Path(path.path(), path.name() + "_out4", path.extention());
//			std::cout << "reading..." << std::endl;
//			IImage<Color> *image = Reader::read<Image<Color>, Color>(path);
//
//			std::cout << "image:" << std::endl;
//			std::cout << '\t' << "rows (height): " << image->rows() << std::endl;
//			std::cout << '\t' << "cols (width): " << image->cols() << std::endl;
//
//			std::cout << "vectorization..." << std::endl;
//			std::vector<IObject*> objects = image->vectorize(new Vectorization<IImage<Color>, Color>);
//
//			std::cout << "end." << std::endl;
//		}
//
//	default:
//		std::cout << "use help" << std::endl;
//		break;
//	}
//
//	return 0;
//}
