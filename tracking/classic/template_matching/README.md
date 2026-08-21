# Object Tracking with Template Matching

## python

    $ python3 template_matching.py


    Example:
            Enter Path and Name Source Video(Search): ./videos/video_1.mp4
            Enter Threshold(float): 0.4
            

## c++

    $ g++ -std=c++17 template_matching.cpp -o output $(pkg-config --cflags --libs opencv4)
    

    Example:
            * Arg1: video path and name
            * Arg2: show template image in new window(yes: show template/ no: don't show)
            * Arg3: Thereshold(float) - if the max_val value becomes smaller than this value,
                    the program will break.

            ./output ./videos/video_1.mp4 yes 0.4
