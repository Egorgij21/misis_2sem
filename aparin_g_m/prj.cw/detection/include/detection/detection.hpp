
 
/// @file detection.hpp*
/// @brief Предоставляет классы и методы обнаружения.


#pragma once

#ifndef DETECTION_HPP
#define DETECTION_HPP

#include <iosfwd>
#include <cstddef>
#include <opencv2/opencv.hpp>

 
/// @brief Типы доступных фильтров.
enum FilterType {
    DEFAULT_THRESHOLD,      ///< Пороговый фильтр по умолчанию.
    GAUSSIAN_BLUR,          ///< Фильтр размытия по Гауссу.
    CANNY_EDGE,             ///< Краевой фильтр Кэнни.
    BACKGROUND_SUBTRACTION  ///< Фильтр вычитания фона.
};

 
/// @class VideoReader
/// @brief Класс для чтения видеофайлов и извлечения кадров.

class VideoReader {
public:

     
/// @brief Инициализирует новый экземпляр класса VideoReader с указанным именем файла.
/// @param filename Путь к видеофайлу для чтения.
VideoReader(const std::string &filename);

     
/// @brief Указывает, есть ли у считывателя следующий кадр, доступный для чтения.
/// @return true, если у считывателя есть следующий кадр; в противном случае false.
bool hasNextFrame() const;

     
/// @brief Получает следующий доступный кадр из видеопотока и сохраняет его в указанной матрице.
/// @param frame Матрица для хранения данных кадра.
void getNextFrame(cv::Mat &frame);

     
/// @brief Получает временую метку последнего извлеченного кадра.
/// @return Временная метка последнего извлеченного кадра.
double getFrameTimestamp() const;

private:
    mutable cv::VideoCapture cap;  

};

 
/// @class Detector
/// @brief Класс для обнаружения объектов из видеокадров с использованием различных фильтров.
class Detector {
public:

     
/// @brief Инициализирует новый экземпляр класса Detector с указанным именем видеофайла.*
/// @param filename Путь к видеофайлу для чтения.
Detector(const std::string &filename) : reader(filename), frame(), timecodes() {}

    
     
/// @brief Обрабатывает текущий кадр, используя пороговый фильтр по умолчанию.
/// @param threshold Пороговое значение, используемое для фильтра.
void processWithThreshold(float threshold);

     
/// @brief Обрабатывает текущий кадр с помощью фильтра размытия по Гауссу.
/// @param threshold Пороговое значение, используемое для фильтра.
/// @param kernelSize The size of the kernel to use for the filter.
void processWithGaussianBlur(float threshold, int kernelSize);

     
/// @brief Обрабатывает текущий кадр с помощью краевого фильтра Canny.
/// @param threshold Пороговое значение, используемое для фильтра.
/// @param threshold1 Первое пороговое значение, используемое для фильтра Кэнни.
/// @param threshold2 Второе пороговое значение, используемое для фильтра Кэнни.

void processWithCannyEdge(float threshold, int threshold1, int threshold2);

     
/// @brief Обрабатывает текущий кадр с помощью фильтра вычитания фона.
/// @param threshold Пороговое значение, используемое для фильтра.
void processWithBackgroundSubtraction(float threshold);

     
/// @brief Обрабатывает текущий кадр, используя указанный тип фильтра и параметры.
/// @param threshold Пороговое значение, используемое для фильтра.
/// @param filterType Тип фильтра для обработки.
/// @param kernelSize Размер ядра, используемого для фильтра (если нужно).
/// @param threshold1 Первое пороговое значение, используемое для фильтра Кэнни (если нужно).
/// @param threshold2 Второе пороговое значение, используемое для фильтра Кэнни (если нужно).

void process(float threshold, FilterType filterType, int kernelSize = 1, float threshold1 = 0.0, float threshold2 = 0.0);


     
/// @brief Возвращает список временных меток для кадров, обработанных на данный момент.
/// @return Список меток времени для кадров, обработанных на данный момент. 
std::vector<double> getTimeCodes();

private:
    VideoReader reader;        
    cv::Mat frame;             
    std::vector<double> timecodes;

};


/// @class VideoCutter*
/// @brief Класс для разрезания видеофайлов на сегменты на основе обнаружения объектов.

class VideoCutter {
public:


     
/// @brief Инициализирует новый экземпляр класса VideoCutter с указанными исходным и конечным путями.*
/// @param srcPath Путь к видеофайлу для чтения.
/// @param destDir Путь к каталогу для сохранения полученных фрагментов видео.
VideoCutter(const std::string &srcPath, const std::string &destDir);

    
/// @brief Разрезает исходный видеофайл на сегменты на основе обнаружения объектов с использованием указанного типа фильтра и параметров.*
/// @param threshold Пороговое значение, используемое для фильтра.
/// @param filterType Тип фильтра для обработки.
/// @param kernelSize Размер ядра, используемого для фильтра (если нужно).
/// @param threshold1 Первое пороговое значение, используемое для фильтра Кэнни (если нужно).
/// @param threshold2 Второе пороговое значение, используемое для фильтра Кэнни (если нужно).

void cut(float threshold, FilterType filterType, int kernelSize = 1, float threshold1 = 0.0, float threshold2 = 0.0);

private:
    std::string srcPath;
    std::string destDir;
};






#endif
