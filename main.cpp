#include <pcl/io/openni_grabber.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/io/png_io.h>
// OpenCV头文件
#include <opencv2/opencv.hpp>

#include <fstream>

using namespace std;
using namespace cv;
using namespace pcl;

static int num_s1 = 0, num_s2 = 0, num_s3 = 0;


 void xtion1 (const boost::shared_ptr<openni_wrapper::Image>& rgb, const boost::shared_ptr<openni_wrapper::DepthImage>& depth, float constant)
 {
     int sizes[2] = {480, 640};
     Mat rgb_mat(2, sizes, CV_8UC3);
     Mat depth_mat(2, sizes,CV_16UC1);

     rgb->fillRGB(640, 480, rgb_mat.data, 640*3);
     for (int i=0; i < 480; ++i)
     {
       for (int j=0; j < 640; ++j)
       {
         cv::Vec3b& pix = rgb_mat.at<cv::Vec3b>(i,j);
         swap(pix[0], pix[2]);
       }
     }
     depth->fillDepthImageRaw(640, 480, (unsigned short*) depth_mat.data);
     imshow("rgb1", rgb_mat);
     imshow("depth1", depth_mat);
     if((char)waitKey(20) == 's')
     {
         std::stringstream rgbFile, depthFile;
         rgbFile << ".//image//xtion1//rgb//rgb_" << setw( 8 ) << setfill( '0' ) << num_s1 << ".jpg";
         depthFile << ".//image//xtion1//depth//depth_" << setw( 8 ) << setfill( '0' ) << num_s1 << ".png";
         ++ num_s1;
         imwrite(rgbFile.str(), rgb_mat);
         vector<int> params;
         params.push_back(CV_IMWRITE_PNG_COMPRESSION);
         params.push_back(0);
         imwrite(depthFile.str(), depth_mat, params);
     }

 }

 void xtion2 (const boost::shared_ptr<openni_wrapper::Image>& rgb, const boost::shared_ptr<openni_wrapper::DepthImage>& depth, float constant)
 {
     int sizes[2] = {480, 640};
     Mat rgb_mat(2, sizes, CV_8UC3);
     Mat depth_mat(2, sizes,CV_16UC1);

     rgb->fillRGB(640, 480, rgb_mat.data, 640*3);
     for (int i=0; i < 480; ++i)
     {
       for (int j=0; j < 640; ++j)
       {
         Vec3b& pix = rgb_mat.at<cv::Vec3b>(i,j);
         swap(pix[0], pix[2]);
       }
     }
     depth->fillDepthImageRaw(640, 480, (unsigned short*) depth_mat.data);
     imshow("rgb2", rgb_mat);
     imshow("depth2", depth_mat);
     if((char)waitKey(20) == 's')
     {
         stringstream rgbFile, depthFile;
         rgbFile << ".//image//xtion2//rgb//rgb_" << setw( 8 ) << setfill( '0' ) << num_s2 << ".jpg";
         depthFile << ".//image//xtion2//depth//depth_" << setw( 8 ) << setfill( '0' ) << num_s2 << ".png";
         ++ num_s2;
         imwrite(rgbFile.str(), rgb_mat);
         vector<int> params;
         params.push_back(CV_IMWRITE_PNG_COMPRESSION);
         params.push_back(0);
         imwrite(depthFile.str(), depth_mat, params);
     }

 }

 void xtion3 (const boost::shared_ptr<openni_wrapper::Image>& rgb, const boost::shared_ptr<openni_wrapper::DepthImage>& depth, float constant)
 {
     int sizes[2] = {480, 640};
     Mat rgb_mat(2, sizes, CV_8UC3);
     Mat depth_mat(2, sizes,CV_16UC1);

     rgb->fillRGB(640, 480, rgb_mat.data, 640*3);
     for (int i=0; i < 480; ++i)
     {
       for (int j=0; j < 640; ++j)
       {
         Vec3b& pix = rgb_mat.at<cv::Vec3b>(i,j);
         swap(pix[0], pix[2]);
       }
     }
     depth->fillDepthImageRaw(640, 480, (unsigned short*) depth_mat.data);
     imshow("rgb3", rgb_mat);
     imshow("depth3", depth_mat);
     if((char)waitKey(20) == 's')
     {
         stringstream rgbFile, depthFile;
         rgbFile << ".//image//xtion3//rgb//rgb_" << setw( 8 ) << setfill( '0' ) << num_s3 << ".jpg";
         depthFile << ".//image//xtion3//depth//depth_" << setw( 8 ) << setfill( '0' ) << num_s3 << ".png";
         ++ num_s3;
         imwrite(rgbFile.str(), rgb_mat);
         vector<int> params;
         params.push_back(CV_IMWRITE_PNG_COMPRESSION);
         params.push_back(0);
         imwrite(depthFile.str(), depth_mat, params);
     }

 }



 int main ()
 {
     namedWindow("rgb1");
     namedWindow("depth1");
     resizeWindow("rgb1", 640,480);
     moveWindow("rgb1", 0, 0);
     resizeWindow("depth1", 640,480);
     moveWindow("depth1", 0, 480);

     namedWindow("rgb2");
     namedWindow("depth2");
     resizeWindow("rgb2", 640,480);
     moveWindow("rgb2", 640, 0);
     resizeWindow("depth2", 640,480);
     moveWindow("depth2", 640, 480);

     namedWindow("rgb3");
     namedWindow("depth3");
     resizeWindow("rgb3", 640,480);
     moveWindow("rgb3", 1280, 0);
     resizeWindow("depth3", 640,480);
     moveWindow("depth3", 1280, 480);

     pcl::Grabber* interface1 = new pcl::OpenNIGrabber("#1");
     pcl::Grabber* interface2 = new pcl::OpenNIGrabber("#2");
     pcl::Grabber* interface3 = new pcl::OpenNIGrabber("#3");
     boost::function<void (const boost::shared_ptr<openni_wrapper::Image>&, const boost::shared_ptr<openni_wrapper::DepthImage>&, float)> f1(&xtion1);
     boost::function<void (const boost::shared_ptr<openni_wrapper::Image>&, const boost::shared_ptr<openni_wrapper::DepthImage>&, float)> f2(&xtion2);
     boost::function<void (const boost::shared_ptr<openni_wrapper::Image>&, const boost::shared_ptr<openni_wrapper::DepthImage>&, float)> f3(&xtion3);

     interface1->registerCallback (f1);
     interface2->registerCallback (f2);
     interface3->registerCallback (f3);

     interface1->start ();
     interface2->start ();
     interface3->start ();

     while (true)
     {
        boost::this_thread::sleep (boost::posix_time::seconds (1));
        if((char)waitKey(30) == 'q')
            break;
     }

     interface1->stop ();
     interface2->stop ();
     interface3->stop ();
   return 0;
 }

