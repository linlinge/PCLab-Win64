#include "formgraph.h"
#include "ui_formgraph.h"
static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;
}


FormGraph::FormGraph(QOpenGLWidget *parent)
{
  timer = new QTimer();
  connect(timer,SIGNAL(timeout()),this,SLOT(update()));   //连接定时器的信号与槽
//       timer->start(50);
  setAcceptDrops(true);
  cloud_=new cloud();
  m_projection.setToIdentity();
}

void FormGraph::updateScale()
{
    float stmp=1.0/cloud_->box_.scale_;
    m_transform.reset();
    m_transform.scale(stmp);
    m_transform.scale(1,this->width()*1.0/this->height(),1);
    update();
}

void FormGraph::initializeGL()
{
  // Initialize OpenGL Backend
  initializeOpenGLFunctions();

  // Set global information
  glClearColor(1.0,1.0,1.0,0.0);
  updateScale();

  // Application-specific initialization
  {
    // Create Shader (Do not release until VAO is created)
    m_program = new QOpenGLShaderProgram();
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, "shaders/simple_trans.vert");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, "shaders/simple.frag");
    m_program->link();
    m_program->bind();

    // Cache Uniform Locations
    transformLoc = m_program->uniformLocation("transform");
    m_transform.scale(1.0f);
    m_program->setUniformValue(transformLoc,m_transform.toMatrix());


    // Create Buffer (Do not release until VAO is created)
    m_vertex.create();
    m_vertex.bind();
    m_vertex.setUsagePattern(QOpenGLBuffer::StaticDraw);
    m_vertex.allocate(cloud_->vtx_.data(), sizeof(V3)*cloud_->vtx_.size());

    // Create Vertex Array Object
    m_object.create();
    m_object.bind();
    m_program->enableAttributeArray(0);
    m_program->enableAttributeArray(1);
    m_program->setAttributeBuffer(0, GL_FLOAT, 0, 3, 24);
    m_program->setAttributeBuffer(1, GL_FLOAT, 12, 3, 24);
    // Release (unbind) all
    m_object.release();
    m_vertex.release();
    m_program->release();
  }

//  m_transform.setScale(1.0);
}

void FormGraph::resizeGL(int width, int height)
{
  updateScale();
}

void FormGraph::paintGL()
{
  // Clear
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


  // Render using our shader
  m_program->bind();  
  m_program->setUniformValue(transformLoc,m_transform.toMatrix());
  {
    m_object.bind();
    glDrawArrays(GL_POINTS, 0, sizeof(V3)*cloud_->vtx_.size());
    m_object.release();
  }
  m_program->release();
}

void FormGraph::teardownGL()
{
  // Currently we have no data to teardown
    m_object.destroy();
    m_vertex.destroy();
    delete m_program;
}


void FormGraph::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_xRot) {
        m_xRot = angle;
    }
}

void FormGraph::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_yRot) {
        m_yRot = angle;
    }
}

void FormGraph::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != m_zRot) {
        m_zRot = angle;
    }
}


void FormGraph::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("text/uri-list"))
           event->acceptProposedAction();
}

void FormGraph::dropEvent(QDropEvent *event)
{
    //注意：这里如果有多文件存在，意思是用户一下子拖动了多个文件，而不是拖动一个目录
    //如果想读取整个目录，则在不同的操作平台下，自己编写函数实现读取整个目录文件名
    QList<QUrl> urls = event->mimeData()->urls();
    if(urls.isEmpty())
        return;


    //往文本框中追加文件名
    foreach(QUrl url, urls) {
         string path=url.toEncoded().toStdString();
         path=path.substr(8,path.size()-8);
         cloud_->Load(path);


         m_vertex.bind();
//         m_vertex.setUsagePattern(QOpenGLBuffer::StaticDraw);
         m_vertex.allocate(cloud_->vtx_.data(), sizeof(V3)*cloud_->vtx_.size());
         m_vertex.release();
        updateScale();

        emit send_signal01(QString::number(cloud_->msh_.VN()).toStdString());
    }
}

void FormGraph::mousePressEvent(QMouseEvent *event)
{
    m_lastPos = event->pos();
}
void FormGraph::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - m_lastPos.x();
    int dy = event->y() - m_lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(m_xRot - 8 * dy);
        setYRotation(m_yRot - 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(m_xRot + 8 * dy);
        setZRotation(m_zRot + 8 * dx);
    }
    m_lastPos = event->pos();
}

void FormGraph::mouseReleaseEvent(QMouseEvent *event)
{

}
