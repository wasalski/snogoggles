////////////////////////////////////////////////////////////////////////
/// \class Viewer::GUIs::NewFrameButton
///
/// \brief   
///
/// \author  Phil Jones <p.jones22@physics.ox.ac.uk>
///
/// REVISION HISTORY:\n
///     30/06/11 : P.Jones - First Revision, new file. \n
///
/// \detail  As brief
///
////////////////////////////////////////////////////////////////////////

#ifndef __Viewer_GUIs_NewFrameButton__
#define __Viewer_GUIs_NewFrameButton__

#include <Viewer/Button.hh>
#include <Viewer/Sprite.hh>
#include <Viewer/Text.hh>

namespace Viewer
{  

namespace GUIs
{

class NewFrameButton : public Button
{
public:
  NewFrameButton( sf::Rect<double>& rect, unsigned int guiID );
  virtual ~NewFrameButton();

  void SetTitle( const std::string& title );
  void RenderT( sf::RenderWindow& windowApp ) { };
  void Render( RWWrapper& windowApp );
protected:
  Text fTitle;
  Sprite fBar;
};

} // ::GUIs

} // ::Viewer

#endif
