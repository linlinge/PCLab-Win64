#ifndef FORMGRAPH_H
#define FORMGRAPH_H

//#include <QOpenGLWindow>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QTimer>
#include <QMouseEvent>

#include <QDrag>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QList>

#include <cloud.h>
#include <QMatrix4x4>
#include <glib/transform3d.h>
namespace Ui {
class FormGraph;
}

class FormGraph : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    cloud* cloud_;
    FormGraph(QOpenGLWidget *parent=0);
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);

private:    
    Ui::FormGraph *ui;
    void updateScale();

signals:
    void send_signal01(string str);    

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void teardownGL();

    /* event */
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


    QTimer *timer;
    GLdouble* vertex;
    GLdouble* normal;


    // OpenGL State Information
    QOpenGLBuffer m_vertex;
    QOpenGLVertexArrayObject m_object;
    QOpenGLShaderProgram *m_program;

    /* transformation */
    Transform3D m_transform;
    QMatrix4x4 m_projection;
    int transformLoc;

    /* trackball */
    QPoint m_lastPos;
    int m_xRot;
    int m_yRot;
    int m_zRot;
};

#endif // FORMGRAPH_H
