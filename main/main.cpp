#include <png.h>
#include <zlib.h>
#include <cstdio>
int main()
{
    int m_width = 0, m_height = 0, color_type = 0;  
    int size = 0, pos = 0, i = 0, j = 0;  
    png_structp png_ptr = NULL;  
    png_infop info_ptr = NULL;

    FILE *fp = fopen("..\\data\\can.png", "rb");
    if (!fp)
    {
        return (-1);
    }
    png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING,0, 0, 0);  
    info_ptr = png_create_info_struct(png_ptr);  

    setjmp(png_jmpbuf(png_ptr));  
    png_init_io(png_ptr, fp); 



    png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_EXPAND, 0);  

    m_width = png_get_image_width(png_ptr,info_ptr);  
    m_height= png_get_image_height(png_ptr,info_ptr);  
    color_type = png_get_color_type(png_ptr,info_ptr);  
    size = m_height*m_width*4;  
   // bgra = (unsigned char*)malloc(size);  
    //row_pointer = png_gets_rows(png_ptr, info_ptr);//取到的数据就是带alpha通道的bgra数据  
    png_destroy_read_struct(&png_ptr, &info_ptr, 0);  
    fclose(fp);  

    return 0;
}