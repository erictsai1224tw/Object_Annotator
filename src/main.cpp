#include "main.hpp"

int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("usage: ./Labeling_Assistance_Tool <Image_Path>\n");
        return -1;
    }

    annotator ann(argv[1]);
    ann.image_processing();
    ann.save_image();

    return 0;
}