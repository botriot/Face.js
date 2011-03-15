#include "cv.h"

IplImage* nice_my_frame(IplImage* frame) {

		IplImage* gray = cvCreateImage(cvSize(frame->width, frame->height), 8, 1);

		cvCvtColor(frame, gray, CV_BGR2GRAY);
		return gray;
}

CvSeq* detect_faces(IplImage* frame, CvHaarClassifierCascade* cascade, CvMemStorage* memory, int min_size) {

		CvSeq* faces = cvHaarDetectObjects(frame, cascade, memory, 1.1, 2, CV_HAAR_DO_CANNY_PRUNING, cvSize(min_size, min_size), cvSize(0, 0));
		cvClearMemStorage(memory);

		return faces;
}
