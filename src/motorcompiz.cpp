#include "motorcompiz.h"
COMPIZ_PLUGIN_20090315 (motorcompiz, MotorCompizPluginVTable);

MotorScreen::MotorScreen(CompScreen * s):
	PluginClassHandler <MotorScreen, CompScreen> (s),
    cScreen (CompositeScreen::get (screen)),
    gScreen (GLScreen::get (screen))

{
}

MotorScreen::~MotorScreen ()
{
}
void MotorScreen::donePaint ()
{

	cScreen->damageScreen ();
    cScreen->donePaint ();
}


MotorWindow::MotorWindow(CompWindow *w):
	PluginClassHandler <MotorWindow, CompWindow> (w),
	window (w),
	cWindow (CompositeWindow::get (w)),
    gWindow (GLWindow::get (w))
{
	WindowInterface::setHandler (window);
    CompositeWindowInterface::setHandler (cWindow);
    GLWindowInterface::setHandler (gWindow);
}

MotorWindow::~MotorWindow ()
{
}

bool MotorWindow::glPaint (const GLWindowPaintAttrib &attrib,
		      const GLMatrix 		&matrix,
		      const CompRegion 		&region,
		      unsigned int		mask)
{

	glm::mat4 transform = glm::make_mat4(matrix.getMatrix());

	//transform = glm::scale(transform, glm::vec3(0.5f));

	mTransform = glm::rotate(mTransform, 1.f, glm::vec3(0,1,0));
	


	GLMatrix newGLMatrix (glm::value_ptr(mTransform*transform));
	
	return gWindow->glPaint(attrib, newGLMatrix, region, mask );
}

bool
MotorCompizPluginVTable::init ()
{
    if (!CompPlugin::checkPluginABI ("core", CORE_ABIVERSION))
	return false;
    if (!CompPlugin::checkPluginABI ("composite", COMPIZ_COMPOSITE_ABI))
	return false;
    if (!CompPlugin::checkPluginABI ("opengl", COMPIZ_OPENGL_ABI))
	return false;

    if (!screen->XShape ())
    {
	compLogMessage ("shelf", CompLogLevelError,
			"No Shape extension found. IPW Usage not enabled \n");
    }

    return true;
}