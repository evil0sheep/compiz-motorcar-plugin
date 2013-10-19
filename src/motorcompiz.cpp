MyPluginScreen::MyPluginScreen (CompScreen *s):
    PluginClassHandler <MyPluginScreen, CompScreen> (s),
    cScreen (CompositeScreen::get (screen)),
    gScreen (GLScreen::get (screen))
{
    ScreenInterface::setHandler (screen);
    CompositeScreenInterface::setHandler (cScreen);
    GLScreenInterface::setHandler (gScreen);
}