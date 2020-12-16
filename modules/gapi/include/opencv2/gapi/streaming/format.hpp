// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html.
//
// Copyright (C) 2020 Intel Corporation

#ifndef OPENCV_GAPI_GSTREAMING_FORMAT_HPP
#define OPENCV_GAPI_GSTREAMING_FORMAT_HPP

#include <opencv2/gapi/gkernel.hpp> // GKernelPackage

namespace cv {
namespace gapi {
namespace streaming {

GAPI_EXPORTS cv::gapi::GKernelPackage kernels();

G_API_OP(GBGR, <GMat(GFrame)>, "org.opencv.streaming.BGR")
{
    static GMatDesc outMeta(const GFrameDesc& in) { return GMatDesc{CV_8U, 3, in.size}; }
};

/** @brief Gets bgr plane from input frame

@note Function textual ID is "org.opencv.streaming.BGR"

@param in Input frame
@return Image in BGR format
*/
GAPI_EXPORTS cv::GMat BGR(const cv::GFrame& in);

} // namespace streaming

/** @brief Makes a copy of the input image. Note that this copy may be not real
(no actual data copied). Use this function to maintain graph contracts,
e.g when graph's input needs to be passed directly to output, like in Streaming mode.

@note Function textual ID is "org.opencv.streaming.copy"

@param in Input image
@return Copy of the input
*/
GAPI_EXPORTS cv::GMat copy(const cv::GMat& in);

/** @brief Makes a copy of the input frame. Note that this copy may be not real
(no actual data copied). Use this function to maintain graph contracts,
e.g when graph's input needs to be passed directly to output, like in Streaming mode.

@note Function textual ID is "org.opencv.streaming.copy"

@param in Input frame
@return Copy of the input
*/
GAPI_EXPORTS cv::GFrame copy(const cv::GFrame& in);

} // namespace gapi
} // namespace cv

#endif // OPENCV_GAPI_GSTREAMING_FORMAT_HPP
