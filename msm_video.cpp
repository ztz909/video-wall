// msm_video.cpp : This file contains the 'main' function. Program execution begins and ends there.
#pragma comment(lib, "winmm.lib")
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv2\core\core.hpp>
#include "opencv2/opencv.hpp"
#include "windows.h"
#include "mmsystem.h"

using namespace cv;

Mat frame0, frame1, frame2, frame3, frame4, frame5, frame6, frame7, frame8;
int window_x = 0;
void resetScreenPosition()
{
    window_x = 0;
}
int main()
{
    int video_playback = 0;
    VideoCapture cap0("videos/Teaser.mov"); // open the top video file
    if (!cap0.isOpened())  // check if success
        return -1;
    namedWindow("Video", WINDOW_NORMAL);
    setWindowProperty("Video", WND_PROP_FULLSCREEN, WINDOW_FULLSCREEN);
    moveWindow("Video", 0, 0);
    //PlaySound(TEXT("C:\\Users\\z.tzifopoulos\\Desktop\\cpp msm\\msm_video\\audio_tracks\\Video0X.wav"), NULL, SND_FILENAME | SND_ASYNC);
    bool loop = true;
    for (;;)
    {
        if (video_playback == 0 && loop)
        {
            for (;;)
            {
                cap0 >> frame0; // get a new frame from camera
                if (frame0.empty()) 
                {
                    cap0.release();
                    cap0.open("videos/Teaser.mov");
                    break;    
                }   
                imshow("Video", frame0);       
                int k = waitKey(22); 
                if (k == 27)
                {
                    video_playback = 9;
                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
                    frame0.release();
                    break;
                }
                if (k == 32)
                {
                    //window_x += 1920;
                    //moveWindow("Video", window_x, 0);    
                    video_playback = 1;
                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
                    loop = false;
                    frame0.release();
                    break; 
                }
            }
        }
        else if (video_playback == 1 && !loop)
        {
            VideoCapture cap1("videos/Video01.mov");
            PlaySound(TEXT("C:\\cpp_msm\\msm_video\\audio_tracks\\Video01.wav"), NULL, SND_FILENAME | SND_ASYNC);
            for (;;)
            {
                cap1 >> frame1; // get a new frame from camera  
                if (frame1.empty())
                {
                    window_x += 1920;
                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
                    moveWindow("Video", window_x, 0);
                    video_playback = 2;
                    frame1.release();
                    break;
                }
                imshow("Video", frame1);
                int k = waitKey(22);
                if (k == 27)
                {
                    loop = true;
                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
                    resetScreenPosition();
                    moveWindow("Video", window_x, 0);
                    video_playback = 0;
                    break;
                }
//               if (k == 32)
//               {
//                   window_x += 1920;
//                   PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
//                   moveWindow("Video", window_x, 0);
//                   video_playback = 2;
//                   frame1.release();
//                   break;
//               }
                //if (waitKey(30) >= 0) break; for any keypress break
            }
        }
        else if (video_playback == 2 && !loop)
        {
            PlaySound(TEXT("C:\\cpp_msm\\msm_video\\audio_tracks\\Video02.wav"), NULL, SND_FILENAME | SND_ASYNC);
            VideoCapture cap2("videos/Video02.mov");
            for (;;)
            {
                cap2 >> frame2; // get a new frame from camera
                if (frame2.empty())
                {
                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
                    window_x += 1920;
                    moveWindow("Video", window_x, 0);
                    video_playback = 3;
                    frame2.release();
                    break;
                }
                imshow("Video", frame2);
                int k = waitKey(22);
                if (k == 27)
                {
                    loop = true;
                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
                    resetScreenPosition();
                    moveWindow("Video", window_x, 0);
                    video_playback = 0;
                    break;
                }
//                if (k == 32)
//                {
//                    window_x += 1920;
//                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
//                    moveWindow("Video", window_x, 0);
//                    video_playback = 3;
//                    frame2.release();
//                    break;
//                }
                //if (waitKey(30) >= 0) break;
            }
        }
        else if (video_playback == 3 && !loop)
        {
            VideoCapture cap3("videos/Video03.mov");
            PlaySound(TEXT("C:\\cpp_msm\\msm_video\\audio_tracks\\Video03.wav"), NULL, SND_FILENAME | SND_ASYNC);
            for (;;)
            {
                cap3 >> frame3; // get a new frame from camera
                if (frame3.empty())
                {
                    window_x += 1920;
                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
                    moveWindow("Video", window_x, 0);
                    video_playback = 4;
                    frame3.release();
                    break;
                }
                imshow("Video", frame3);
                int k = waitKey(22);
                if (k == 27)
                {
                    loop = true;
                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
                    resetScreenPosition();
                    moveWindow("Video", window_x, 0);
                    video_playback = 0;
                    break;
                }
//                if (k == 32)
//                {
//                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
//                    window_x += 1920;
//                    moveWindow("Video", window_x, 0);
//                    video_playback = 4;
//                    frame3.release();
//                    break;
//                }
                //if (waitKey(30) >= 0) break;
            }
        }
        else if (video_playback == 4 && !loop)
        {
            VideoCapture cap4("videos/Video04.mov");
            PlaySound(TEXT("C:\\cpp_msm\\msm_video\\audio_tracks\\Video04.wav"), NULL, SND_FILENAME | SND_ASYNC);
            for (;;)
            {
                cap4 >> frame4; // get a new frame from camera
                if (frame4.empty())
                {
                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
                    window_x += 1920;
                    moveWindow("Video", window_x, 0);
                    video_playback = 5;
                    frame4.release();
                    break;
                }
                imshow("Video", frame4);
                int k = waitKey(22);
                if (k == 27)
                {
                    loop = true;
                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
                    resetScreenPosition();
                    moveWindow("Video", window_x, 0);
                    video_playback = 0;
                    break;
                }
//                if (k == 32)
//                {
//                    window_x += 1920;
//                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
//                    moveWindow("Video", window_x, 0);
//                    video_playback = 5;
//                    frame4.release();
//                    break;
//                }
                //if (waitKey(30) >= 0) break;
            }
        }
        else if (video_playback == 5 && !loop)
        {
            VideoCapture cap5("videos/Video05.mov");
            PlaySound(TEXT("C:\\cpp_msm\\msm_video\\audio_tracks\\Video05.wav"), NULL, SND_FILENAME | SND_ASYNC);
            for (;;)
            {
                cap5 >> frame5; // get a new frame from camera
                if (frame5.empty())
                {
                    window_x += 1920;
                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
                    moveWindow("Video", window_x, 0);
                    video_playback = 6;
                    frame5.release();
                    break;
                }
                imshow("Video", frame5);
                int k = waitKey(22);
                if (k == 27)
                {
                    loop = true;
                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
                    resetScreenPosition();
                    moveWindow("Video", window_x, 0);
                    video_playback = 0;
                    break;
                }
 //               if (k == 32)
 //               {
 //                   window_x += 1920;
 //                   PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
 //                   moveWindow("Video", window_x, 0);
 //                   video_playback = 6;
 //                   frame5.release();
 //                   break;
 //               }
                //if (waitKey(30) >= 0) break;
            }
        }
        else if (video_playback == 6 && !loop)
        {
            VideoCapture cap6("videos/Video06.mov");
            PlaySound(TEXT("C:\\cpp_msm\\msm_video\\audio_tracks\\Video06.wav"), NULL, SND_FILENAME | SND_ASYNC);
            for (;;)
            {
                cap6 >> frame6; // get a new frame from camera
                if (frame6.empty())
                {
                    window_x += 1920;
                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
                    moveWindow("Video", window_x, 0);
                    video_playback = 7;
                    frame6.release();
                    break;
                }
                imshow("Video", frame6);
                int k = waitKey(22);
                if (k == 27)
                {
                    loop = true;
                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
                    resetScreenPosition();
                    moveWindow("Video", window_x, 0);
                    video_playback = 0;
                    break;
                }
 //               if (k == 32)
 //               {
 //                   window_x += 1920;
 //                   PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
 //                   moveWindow("Video", window_x, 0);
 //                   video_playback = 7;
 //                   frame6.release();
 //                   break;
 //               }
                //if (waitKey(30) >= 0) break;
            }
        }
        else if (video_playback == 7 && !loop)
        {
            VideoCapture cap7("videos/Video07.mov");
            PlaySound(TEXT("C:\\cpp_msm\\msm_video\\audio_tracks\\Video07.wav"), NULL, SND_FILENAME | SND_ASYNC);
            for (;;)
            {
                cap7 >> frame7; // get a new frame from camera
                if (frame7.empty())
                {
                    window_x += 1920;
                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
                    moveWindow("Video", window_x, 0);
                    video_playback = 8;
                    frame7.release();
                    break;
                }
                imshow("Video", frame7);
                int k = waitKey(22);
                if (k == 27)
                {
                    loop = true;
                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
                    resetScreenPosition();
                    moveWindow("Video", window_x, 0);
                    video_playback = 0;
                    break;
                }
//                if (k == 32)
//                {
//                    window_x += 1920;
//                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
//                    moveWindow("Video", window_x, 0);
//                    video_playback = 8;
//                    frame7.release();
//                    break;
//                }
                //if (waitKey(30) >= 0) break;
            }
        }
        else if (video_playback == 8 && !loop)
        {
            VideoCapture cap8("videos/Video08.mov");
            PlaySound(TEXT("C:\\cpp_msm\\msm_video\\audio_tracks\\Video08.wav"), NULL, SND_FILENAME | SND_ASYNC);
            for (;;)
            {
                cap8 >> frame8; // get a new frame from camera
                if (frame8.empty())
                {
                    resetScreenPosition();
                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
                    moveWindow("Video", window_x, 0);
                    video_playback = 0;
                    frame8.release();
                    loop = true;
                    break;
                }
                imshow("Video", frame8);
                //if (waitKey(30) >= 0) break;
                int k = waitKey(22);
                if (k == 27)
                {
                    loop = true;
                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
                    resetScreenPosition();
                    moveWindow("Video", window_x, 0);
                    video_playback = 0;
                    break;
                }
//                if (k == 32)
//                {
//                    resetScreenPosition();
//                    PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
//                    moveWindow("Video", window_x, 0);
//                    video_playback = 0;
//                    frame8.release();
//                    loop = true;
//                    break;
//                }
            }
        }
        else if (video_playback == 9) break;
        else break;
    // mute audio from playsound
    
    // the camera will be deinitialized automatically in VideoCapture destructor
    }
    return 0;
}