#include "cloud.h"
cloud::cloud(){
    vtx_.push_back(V3(0,0.75f,1.0f));
    vtx_.push_back(V3(1.0f,0.0f,0.0f));
    vtx_.push_back(V3(-0.75f,-0.75f,1.0f));
    vtx_.push_back(V3(1.0f,0.0f,0.0f));
    vtx_.push_back(V3(0.75f,-0.75f,1.0f));
    vtx_.push_back(V3(1.0f,0.0f,0.0f));
    GetAABB();
}
void cloud::Load(string path)
{
    int mask;
    Clear();
    vcg::tri::io::ImporterPLY<MyMesh>::Open(msh_, path.c_str(),mask);
    for(int i=0;i<msh_.VN();i++){
        float xtmp=msh_.vert[i].P().X();
        float ytmp=msh_.vert[i].P().Y();
        float ztmp=msh_.vert[i].P().Z();
        vtx_.push_back(V3(xtmp,ytmp,ztmp));
        vtx_.push_back(V3(0.0f,0.0f,1.0f));
    }
    GetAABB();
} 

void cloud::GetAABB()
{
    float cx,cy,cz;
    cx=cy=cz=0;
    for(int i=0;i<vtx_.size();i+=2){
        cx+=vtx_[i].x;
        cy+=vtx_[i].y;
        cz+=vtx_[i].z;

        box_.min_.setX(min(box_.min_.x(),vtx_[i].x));
        box_.min_.setY(min(box_.min_.y(),vtx_[i].y));
        box_.min_.setZ(min(box_.min_.z(),vtx_[i].z));

        box_.max_.setX(max(box_.max_.x(),vtx_[i].x));
        box_.max_.setY(max(box_.max_.y(),vtx_[i].y));
        box_.max_.setZ(max(box_.max_.z(),vtx_[i].z));
    }
    box_.cen_.setX(cx/(vtx_.size()/2));
    box_.cen_.setY(cy/(vtx_.size()/2));
    box_.cen_.setZ(cz/(vtx_.size()/2));

    box_.scale_=max(box_.scale_,std::abs(box_.max_.x()-box_.min_.x()));
    box_.scale_=max(box_.scale_,std::abs(box_.max_.y()-box_.min_.y()));
    box_.scale_=max(box_.scale_,std::abs(box_.max_.z()-box_.min_.z()));
}

void cloud::Clear()
{
    msh_.Clear();
    box_.Clear();
    vtx_.clear();
}
