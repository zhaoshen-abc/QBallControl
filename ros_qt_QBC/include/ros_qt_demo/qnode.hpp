/**
 * @file /include/class1_ros_qt_demo/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef class1_ros_qt_demo_QNODE_HPP_
#define class1_ros_qt_demo_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

// To workaround boost/qt4 problems that won't be bugfixed. Refer to
//    https://bugreports.qt.io/browse/QTBUG-22829
#ifndef Q_MOC_RUN
#include <ros/ros.h>
#endif
#include <string>
#include "std_msgs/String.h"
#include <QThread>
#include <QStringListModel>
#include "ros_qt_demo/uav_data.h"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace class1_ros_qt_demo {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
    QNode(int argc, char** argv ,QStringListModel *logging_model_);
  virtual ~QNode();
  bool init();
    bool init(const std::string &master_url, const std::string &host_url);
  void run();
    void doMsg(const ros_qt_demo::uav_data::ConstPtr& msg_p);

  /*********************
  ** Logging
  **********************/
  enum LogLevel {
           Debug,
           Info,
           Warn,
           Error,
           Fatal
   };


  void log( const LogLevel &level, const std::string &msg);

signals:
    void getdata();

Q_SIGNALS:
  void loggingUpdated();
    void rosShutdown();

public:
    ros_qt_demo::uav_data msg;

private:
    int init_argc;
    char** init_argv;
    ros::Subscriber subscriber;
    QStringListModel *logging_model;

};

}  // namespace class1_ros_qt_demo

#endif /* class1_ros_qt_demo_QNODE_HPP_ */
