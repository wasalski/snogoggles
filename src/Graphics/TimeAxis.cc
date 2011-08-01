#include <SFML/Graphics/Rect.hpp>

#include <Viewer/Rect.hh>
#include <Viewer/Colour.hh>
#include <Viewer/ColourPalette.hh>
#include <Viewer/TimeAxis.hh>
using namespace Viewer;

double
TimeAxis::ScaleTime( double time )
{
  if( time < 240.0 ) 
    return time / 240.0 * 0.1;
  else if( time < 340.0 )
    return ( time - 240.0 ) / 100.0 * 0.5 + 0.1;
  else
    return ( time - 340.0 ) / 160.0 * 0.4 + 0.6;
}

void
TimeAxis::Fill()
{
  for( unsigned int yPixel = 0; yPixel < fHeight; yPixel++ )
    {
      const double time = static_cast<double>( fHeight - yPixel - 1 ) / static_cast<double>( fHeight ) * 500.0;
      const double scale = ScaleTime( time );
      Colour colour = ColourPalette::gPalette->GetColour( scale );
      for( unsigned int xPixel = 0; xPixel < fWidth; xPixel++ )
	{
	  int pixel = ( xPixel + yPixel * fWidth ) * 4;
	  fPixels[pixel] = colour.r;
	  fPixels[pixel + 1] = colour.g;
	  fPixels[pixel + 2] = colour.b;
	  fPixels[pixel + 3] = colour.a;
	}
    }
}
