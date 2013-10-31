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
		CompScreen *screen;
		CompositeScreen *cScreen;
		GLScreen	*gScreen;

		MotorScreen (CompScreen *);
		~MotorScreen ();

		virtual void preparePaint (int);
		virtual void donePaint ();

		virtual bool glPaintOutput (const GLScreenPaintAttrib &attrib,
				    const GLMatrix 	      &matrix,
				    const CompRegion 	      &region,
				    CompOutput 		      *output,
				    unsigned int	      mask);


		
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

		virtual bool glPaint (const GLWindowPaintAttrib &attrib,
		      const GLMatrix 		&matrix,
		      const CompRegion 		&region,
		      unsigned int		mask);

		bool isTransformable();
};

#define MOTOR_SCREEN(screen)						       \
    MotorScreen *ms = MotorScreen::get (screen);

#define MOTOR_WINDOW(window)						       \
    MotorWindow *mw = MotorWindow::get (window);


class MotorCompizPluginVTable :
	public CompPlugin::VTableForScreenAndWindow <MotorScreen, MotorWindow>
{
	public:
		bool init ();

		//PLUGIN_OPTION_HELPER (MotorScreen);
};

