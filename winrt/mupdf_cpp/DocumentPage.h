#pragma once

#include "RectList.h"
#include <collection.h>


/* Used for binding to the xaml in the scroll view. */
using namespace Windows::UI::Xaml::Media::Imaging;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::Foundation::Collections;

typedef enum {
    FULL_RESOLUTION = 0,
    THUMBNAIL,
    DUMMY,
    NOTSET
} Page_Content_t;

        
namespace mupdf_cpp
{
    [Windows::UI::Xaml::Data::Bindable] // in c++, adding this attribute to ref classes enables data binding for more info search for 'Bindable' on the page http://go.microsoft.com/fwlink/?LinkId=254639 

    public ref class DocumentPage sealed
    {
    private:
        int height;
        int width;
        double zoom;
        WriteableBitmap^ image;
        Page_Content_t content;

    public:
        DocumentPage(void);

        property int Content
        {
            int get() { return ((int) content); }
            void set(int value)
            {
                if (value > NOTSET)
                { 
                    throw ref new Platform::InvalidArgumentException(); 
                }
                content = (Page_Content_t) value;
            }
        }

        property int Height
        {
            int get() { return height; }
            void set(int value)
            {
                if (value < 0) 
                { 
                    throw ref new Platform::InvalidArgumentException(); 
                }
                height = value;
            }
        }

        property int Width
        {
            int get() { return width; }
            void set(int value)
            {
                if (value < 0) 
                { 
                    throw ref new Platform::InvalidArgumentException(); 
                }
                width = value;
            }
        }

        property double Zoom
        {
            double get() { return zoom; }
            void set(double value)
            {
                if (value < 0) 
                { 
                    throw ref new Platform::InvalidArgumentException(); 
                }
                zoom = value;
            }
        }

        property WriteableBitmap^ Image
        {
            WriteableBitmap^ get() { return image; }
            void set(WriteableBitmap^ value)
            {
                image = value;
            }
        }
    };
}
