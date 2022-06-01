// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#ifndef __HAAR_DETECTOR_HPP__
#define __HAAR_DETECTOR_HPP__

#include <yarp/dev/DeviceDriver.h>

#include <opencv2/objdetect.hpp>

#include <opencv2/face/facemark.hpp>

#include <opencv2/face.hpp>

#include <opencv2/opencv.hpp>

#include <opencv2/face/facemarkLBF.hpp>

#include "IDetector.hpp"

namespace roboticslab
{

/**
 * @ingroup YarpPlugins
 * @defgroup HaarDetector
 * @brief Contains roboticslab::HaarDetector.
 */
class HaarDetector : public yarp::dev::DeviceDriver,
                     public IDetector
{
public:
    bool open(yarp::os::Searchable& config) override;
    bool detect(const yarp::sig::Image& inYarpImg, yarp::os::Bottle& detectedObjects) override;

private:
    cv::CascadeClassifier object_cascade;
    cv::Ptr<cv::face::Facemark> facemark;
    std::vector< std::vector<cv::Point2f> > shapes;
};

} // namespace roboticslab

#endif // __HAAR_DETECTOR_HPP__
