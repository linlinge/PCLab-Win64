#ifndef GPOINTCLOUD_H
#define GPOINTCLOUD_H
#include <glib/VCGExtend.h>
#include <QString>
#include <QMatrix4x4>
#include <QOpenGLBuffer>
#include <QOpenGLContext>
#include <QOpenGLVertexArrayObject>
#include <vector>
#include <glib/V3.hpp>
#include <math.h>
using namespace std;
class AABB{
public:
    QVector3D min_;
    QVector3D max_;
    QVector3D cen_;
    float scale_;
    AABB(){
        min_=QVector3D(INFINITY,INFINITY,INFINITY);
        max_=QVector3D(-INFINITY,-INFINITY,-INFINITY);
        cen_=QVector3D(0,0,0);
        scale_=1.0;
    }
    void Clear(){
        min_=QVector3D(INFINITY,INFINITY,INFINITY);
        max_=QVector3D(-INFINITY,-INFINITY,-INFINITY);
        cen_=QVector3D(0,0,0);
        scale_=1.0;
    }
};


class cloud
{
public:
    cloud::cloud();
    void Load(string path);
    MyMesh msh_; // mesh    
    vector<V3> vtx_;
    AABB box_;

    void Clear();

private:
    void GetAABB();

};

#endif // GPOINTCLOUD_H
