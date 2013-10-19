#include <core/core.h>
#include <core/pluginclasshandler.h>
#include <composite/composite.h>
#include <opengl/opengl.h>

class MotorScreen :
	public PluginClassHandler <MotorScreen, CompScreen>,
	public GLScreenInterface,
	public CompositeScreenInterface
{
	public:
		CompositeScreen *cScreen;
		GLScreen	*gScreen;

		MotorScreen (CompScreen *);
		~MotorScreen ();
};

class MotorWindow :
	public PluginClassHandler <MotorWindow, CompWindow>,
	public GLWindowInterface
{
	public:

		MotorWindow (CompWindow *);
		~MotorWindow ();
};
class MyPluginVTable :
	public CompPlugin::VTableForScreenAndWindow <MotorScreen, MotorWindow>
{
	public:
		bool init ();
};