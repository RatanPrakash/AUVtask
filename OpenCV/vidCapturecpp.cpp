
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{

  VideoCapture cap;
  Mat frame;
  string file;

  /* Enter the path of a file if the file is not in the directory of the project */
//  cout<<"\nEnter name of a video file with extension: ";
//
//  /* cin function cannot read space. Hence we have used getline function here. */
//  getline(cin, file);

    file = "/Users/ratanprakash/Desktop/OpenCV/OpenCV/test.mp4";

  cout<<"\n\n";

  /* open function is used to open the file */
  cap.open(file);

  /* Checking if the video file successfully opened. */
  if (cap.isOpened() == 0)
  {
    cout<< "\nError..!!\n";
    cout<<"\nMake sure=>";
    cout<<"\n1. Desired video file is in the folder of the project";
    cout<<"\n2. You have mentioned the extension of the file\n\n";
    exit(0);
  }

  /* Playing video as per mentioned frame rate */
  while (cap.read(frame))
  {

    /* You can process frame as per your requirement */

    /* namedWindow() is used to create a window with the mentioned name. In our case, window name is 'Playing video' */
    namedWindow("Playing video", WINDOW_AUTOSIZE);

    /* Imshow function is used to display an image and a video is basically sequence of fast moving images */
    imshow("Playing video", frame);

    /* Press esc to exit */
    if (waitKey(100) == 27)
    {
      break;
    }

  }

  /* when everything done, release the video capture object */
  cap.release();

  /* Closing all the frames after playing whole video */
  destroyAllWindows();

  return 0;

}


