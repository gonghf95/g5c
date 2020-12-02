#ifndef G5C_FRAME_APPLICATION_H
#define G5C_FRAME_APPLICATION_H

#include <QApplication>

namespace g5c
{

namespace frame
{

class G5cApp : public QApplication
{
public:
    G5cApp(int& argc, char** argv);

};

} // namespace frame

} // namespace g5c

#endif /* G5C_FRAME_APPLICATION */
