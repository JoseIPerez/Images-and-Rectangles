#include <iostream>
#include <stdio.h>
#include "Frame.h"
#include "Image.h"
#include "Rectangle.h"
#include <fstream>
#include "global.h"

using namespace std;

Frame frame(720, 480);

int main(int argc, char * argv[]) {
    // Construct the ffmpeg command to run.
    const char * cmd =
    "ffmpeg              "
    "-y                  "
    "-hide_banner        "
    "-f rawvideo         " // input to be raw video data
    "-pixel_format rgb24 "
    "-video_size 720x480 "
    "-r 60               " // frames per second
    "-i -                " // read data from the standard input stream
    "-pix_fmt yuv420p    " // to render with Quicktime
    "-vcodec mpeg4       "
    "-an                 " // no audio
    "-q:v 5              " // quality level; 1 <= q <= 32
    "output.mp4          ";
    
    // Run the ffmpeg command and get pipe to write into its standard input stream.
    FILE * pipe = popen(cmd, "w");
    if (pipe == 0) {
        cout << "error: " << strerror(errno) << endl;
        return 1;
    }
    vector<Object *> obj;
    Rectangle *rect = new Rectangle(10, 20, 0, 0, 0xff, 0x00, 0x00);
    rect->setSpeed(90, 90);
    obj.push_back(rect);
    
    Image *img = new Image();
    img->load("tinyfin.bmp", 150, 150);
    img->setSpeed(0, 100);
    obj.push_back(img);
    
    Rectangle *rect2 = new Rectangle(100, 100, 100, 100, 0x00, 0xff, 0xff);
    rect2->setSpeed(90, 90);
    obj.push_back(rect2);
    
    Image *img2 = new Image();
    img2->load("penguin.bmp", 150, 150);
    img2->getX(200.0);
    img2->getY(150.0);
    img2->setSpeed(100, 100);
    obj.push_back(img2);
    
    int num_frames = duration_in_seconds * frames_per_second;
    for (int i = 0; i < num_frames; ++i) {
        double dt = 1.0 / frames_per_second;
        frame.clear();
        for (int j = 0; j < obj.size(); ++j){
            obj[j]->draw();
            obj[j]->update(dt);
        }
        frame.write(pipe);
    }
    
    fflush(pipe);
    pclose(pipe);
    
    cout << "num_frames: " << num_frames << endl;
    cout << "Done." << endl;
    
    return 0;
}
