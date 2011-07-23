////////////////////////////////////////////////////////////////////////
/// \class Viewer::World
///
/// \brief   
///
/// \author  Olivia Wasalski <wasalski@triumf.ca>
///
/// REVISION HISTORY:\n
///     20/07/11 : Olivia Wasalski - First Revision, new file. \n
///
/// \detail  
///
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
/// \class Viewer::World::NoVisAttributesError
///
/// \brief   
///
/// \author  Olivia Wasalski <wasalski@triumf.ca>
///
/// REVISION HISTORY:\n
///     20/07/11 : Olivia Wasalski - First Revision, new file. \n
///
/// \detail  
///
////////////////////////////////////////////////////////////////////////

#ifndef __Viewer_World__
#define __Viewer_World__

#include <Viewer/Volume.hh>
#include <Viewer/VisMap.hh>
#include <Viewer/Serializable.hh>
#include <string>
#include <stdexcept>

namespace Viewer
{

class World : public Serializable
{
public:

    World() { }
    World( Volume& volume, VisMap& visAttributes );

    inline const Volume& GetVolume() const;
    inline void SetVolume( Volume& volume );

    inline const VisMap& GetVisMap() const;
    void SetVisMap( VisMap& visMap );

    inline void Render();

    void Load( ConfigurationTable* configTable );
    void Save( ConfigurationTable* configTable ) const;

private:

    void SetVisAttributes( Volume* volume );

    Volume fVolume;
    VisMap fVisMap;

}; // class World

////////////////////////////////////////////////////////////////////////
// inline methods
////////////////////////////////////////////////////////////////////////

const Volume& World::GetVolume() const
{
    return fVolume;
}

void World::SetVolume( Volume& volume )
{
    fVolume = volume;
}

const VisMap& World::GetVisMap() const
{
    return fVisMap;
}

void World::Render()
{
    fVolume.Render();
}

} // ::Viewer

#endif // __Viewer_World
