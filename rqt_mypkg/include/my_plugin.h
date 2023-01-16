/*
  Copyright 2018
*/
#ifndef RQT_MYPKG_CPP_MY_PLUGIN_H
#define RQT_MYPKG_CPP_MY_PLUGIN_H

#include <ros/ros.h>
#include <rqt_gui_cpp/plugin.h>
#include <QWidget>
#include <iostream>
#include "rqt_mypkg/ui_my_plugin.h"
#include <std_msgs/UInt16.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/JointState.h>


//#include "rqt_mypkg/FAC_HoverService.h"
//#include <QKeyEvent> 
namespace rqt_mypkg_cpp
{

class MyPlugin : public rqt_gui_cpp::Plugin
{    
    Q_OBJECT
public:
    MyPlugin();
    virtual void initPlugin(qt_gui_cpp::PluginContext& context);
    virtual void shutdownPlugin();

private slots:

   // void Arm_Callback(bool val);    
    void publisher_set(const ros::TimerEvent&);
    void callback_set(const ros::TimerEvent&);
    void qsc_x_callback(int val);
    void qsc_y_callback(int val);
    void qsc_z_callback(int val);
    void btn_Start_Callback(bool val);
    void AngleSubscriber_Callback(const geometry_msgs::Twist &msg);
 //   bool FAC_Hover_Callback(rqt_mypkg::FAC_HoverService::Request &req, rqt_mypkg::FAC_HoverService::Response &res);
 //   void keyPressEvent(QKeyEvent *event); 
    
    private:
    Ui::MyPluginWidget ui_;
    QWidget* widget_;
    ros::Publisher publisher;         //이건 GUI Shutdown 용이라서 건들면 안 됨.
    ros::Publisher cmd_Publisher;
    ros::Subscriber AngleSubscriber;
    ros::Timer Publisher_set;
    ros::Timer Callback_set;



    //    ros::ServiceServer HoverServer;
};

}  // namespace rqt_mypkg_cpp

#endif  // RQT_MYPKG_CPP_MY_PLUGIN_H
