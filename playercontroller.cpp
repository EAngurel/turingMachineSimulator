#include "playercontroller.h"

/*playercontroller::playercontroller(QObject *parent) : QObject(parent)
{

}*/

void playercontroller::run()
{
    msleep(abs(3000 - (30 * velocity)));
    emit moving();
}
