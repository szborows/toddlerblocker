#include <X11/Xlib.h>
#include <iostream>

using namespace std;
constexpr auto KEY_ENTER = 36;
constexpr auto MOD_CTRL = 4;

int main(int, char **)
{
    Display * display = XOpenDisplay(nullptr);
    if (nullptr == display) {
        cerr << "could not open display :/" << endl;
        return 1;
    }

    Window root = DefaultRootWindow(display);
    XGrabPointer(display, root, 1, ButtonPress, GrabModeAsync, GrabModeAsync, None, None, CurrentTime);
    XGrabKeyboard(display, root, 0, GrabModeAsync, GrabModeAsync, CurrentTime);
    XSelectInput(display, root, KeyPressMask);

    XEvent evt;
    while (XNextEvent(display, &evt), 1) {
        if (KeyPress == evt.type) {
            auto keyEvent = reinterpret_cast<XKeyEvent *>(&evt);
            if (KEY_ENTER == keyEvent->keycode && MOD_CTRL == keyEvent->state) {
                XUngrabKeyboard(display, CurrentTime);
                XUngrabPointer(display, CurrentTime);
                break;
            }
        }
    }
}
