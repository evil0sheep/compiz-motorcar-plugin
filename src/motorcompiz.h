#include <core/core.h>
class MyPluginScreen :
	public PluginClassHandler <MyScreen, CompScreen>,
	public ScreenInterface,
	public MypluginOptions
{
	public:

		MyPluginScreen (CompScreen *);
		~MyPluginScreen ();
}
class MyPluginVTable :
	public CompPlugin::VTableForScreenAndWindow <MyPluginScreen, MyPluginWindow>
{
	public:
		bool init ();
}