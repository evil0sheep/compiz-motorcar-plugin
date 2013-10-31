#include <core/core.h>
#include <core/pluginclasshandler.h>
#include <composite/composite.h>
#include <opengl/opengl.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdio.h>

#include "motorcompiz_options.h"
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

		void donePaint ();
};

class MotorWindow :
	public PluginClassHandler <MotorWindow, CompWindow>,
	public WindowInterface,
	public CompositeWindowInterface,
	public GLWindowInterface
{
	public:
		CompWindow *window;
		CompositeWindow *cWindow;
		GLWindow   *gWindow;

		glm::mat4 mTransform;

		MotorWindow (CompWindow *);
		~MotorWindow ();

		bool glPaint (const GLWindowPaintAttrib &attrib,
		      const GLMatrix 		&matrix,
		      const CompRegion 		&region,
		      unsigned int		mask);
};

#define MOTORCOMPIZ_SCREEN(screen)						       \
    MotorScreen *ms = MotorScreen::get (screen);

#define MOTORCOMPIZ_WINDOW(window)						       \
    MotorWindow *mw = MotorWindow::get (window);


class MotorCompizPluginVTable :
	public CompPlugin::VTableForScreenAndWindow <MotorScreen, MotorWindow>
{
	public:
		bool init ();

		//PLUGIN_OPTION_HELPER (MotorScreen);
};

