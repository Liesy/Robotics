#### 山东大学 计算机科学与技术学院 自主智能系统与机器人 实验报告

#### 机器人操作系统（ROS）实训

#### 智能19 李阳 201900170249

---

## 练习ROS常用命令并运行小海龟程序

### 练习ROS常用命令

1. roscore命令用来打开节点管理器，是我们在运行ROS系统时必须要首先运行的指令
2. rosrun命令用来运行某个功能包里的某个结点，后面跟两个参数，第一个参数是功能包名，第二个参数是结点名，在输入功能包名后，按tab键，可以显示该功能包内的节点名。 如：rosrun turtlesim turtlesim_node
3. ROS里面有一些rqt开头的工具，这都是一些可视化工具，比如rqt_graph是一个用来显示系统计算图的一个工具，通过这张图我们可以很快的了解这个系统的全貌
4. rosnode工具用来显示系统中所有节点的相关信息
5. rosnode list指令用来把系统中所有的节点都列出来
6. rosnode info指令用来查看某一个节点具体的信息是什么，如rosnode info /turtlesim（/turtlesim是节点名）
7. rosout是ros一个默认的话题，用来采集ros节点的运动信息，给上面的界面进行显示
8. rostopic list命令可以查看当前系统所有的列表

<img src="D:\大二下\机器人\实验\Robotics\image\ros1.jpg" alt="ros1" style="zoom:80%;" />

### 运行小海龟程序

<img src="D:\大二下\机器人\实验\Robotics\image\ros1。1.jpg" alt="ros1。1" style="zoom:80%;" />

## 编写ROS的第一个程序hello_world

- 创建catkin工作空间并编译工作空间。
- 设置并检查环境变量。
- 创建功能包，编写功能包源代码。
- 完成功能包的编译配置，对功能包进行编译。
- 启动功能包。

<img src="D:\大二下\机器人\实验\Robotics\image\ros2.jpg" alt="ros2" style="zoom:80%;" />

<img src="D:\大二下\机器人\实验\Robotics\image\ros3.jpg" alt="ros3" style="zoom:80%;" />

## ROS话题通信实验

### rqt_graph的安装与运行

**rqt_graph是一个用来显示系统计算图的一个工具，通过这张图我们可以很快的了解这个系统的全貌。**

![ros4](D:\大二下\机器人\实验\Robotics\image\ros4.jpg)

### rostopic命令工具

1. rostopic echo可以显示在某个话题上发布的数据。

   ![ros5](D:\大二下\机器人\实验\Robotics\image\ros5.jpg)

2. rostopic list命令可以查看当前系统所有的列表，使用verbose选项可以显示出有关所发布和订阅的话题及其类型的详细信息。

   ![ros6](D:\大二下\机器人\实验\Robotics\image\ros6.jpg)

### ROS Messages

1. rostopic type命令用来查看所发布话题的消息类型。

2. 使用rostopic pub来发布消息。

   ![ros7](D:\大二下\机器人\实验\Robotics\image\ros7.jpg)

3. 使用rqt_plot来**实时**显示一个发布到某个话题上的数据变化图形。

   ![ros8](D:\大二下\机器人\实验\Robotics\image\ros8.jpg)

## ROS服务通信实验

1. ROS Services：rosservice可以轻松的使用ROS客户端/服务器框架提供的服务，rosservice提供了很多可以在topic上使用的命令。

2. 使用rosparam：rosparam使得我们能够存储并操作ROS[参数服务器]上的数据，参数服务器能够存储整型、浮点型、布尔型、字符型、字典和列表等数据类型。

   ![ros9](D:\大二下\机器人\实验\Robotics\image\ros9.jpg)

## 自定义消息的发布和订阅

### 发布者设计

**想要实现一个发布者，必须满足以下操作：**

1. 初始化ROS节点

2. 向ROS Master注册节点信息，包括发布的话题名和话题中的消息类型

3. 创建消息数据

4. 按照一定频率循环发布消息

   ![ros10](D:\大二下\机器人\实验\Robotics\image\ros10.jpg)

### 订阅者设计

**为了实现一个订阅者，订阅者必须有以下操作：**

1. 初始化ROS节点

2. 订阅需要的话题

3. 循环等待话题消息，接收到消息后进入回调函数

4. 在回调函数中完成消息处理

   ![ros11](D:\大二下\机器人\实验\Robotics\image\ros11.jpg)

### 自定义消息类型、

1. 当ros中已经定义好的消息无法满足我们的需求时，我们就需要自己去定义我们需要的消息，本部分内容我们要完成对名为person的这样一个信息的传送，包括年龄、性别、等信息，我们需要把我们定义的这些消息放在一个.msg文件中，取名为Person。

2. 编写好发布者和订阅者的程序。

3. 先打开节点管理器，然后再运行发布者和订阅者，这个时候就可以发现两者进行了数据通信了，在此时关闭节点管理器不影响他们之间的数据传输，因为节点管理器只是帮助他们建立起连接，不参与他们的数据传输，一旦连接建立完成，它就不发挥作用了。

   ![ros12](D:\大二下\机器人\实验\Robotics\image\ros12.jpg)

## 自定义服务的请求和服务

### 客户端的编程实现

**本部分内容要实现编写一个客户端，发送产生一个新海龟的请求Request给我们的海龟仿真器（Server端），Server端接收到后，产生一个新的海龟，然后返回一个Response给客户端Client，本例中中间的Service是之前用过的Spawn，他的数据结构在turtlesim里面自定义的turtlesim：：Spawn**

想要实现一个客户端，必须有以下操作：

1. 初始化ROS节点

2. 创建一个Client实例

3. 发布服务请求数据

4. 等待Server处理之后的应答结果

   ![ros13](D:\大二下\机器人\实验\Robotics\image\ros13.jpg)

### 服务器端的编程实现

**本例中通过要实现让Server发送速度的指令，client端发布request去控制Service是否要去给海龟发送指令，client端相当于海龟运动和停止的开关，当他发一个Request后海龟就运动，再发一个海龟就停止，Server端接收指令，并完成海龟运动指令的发送，在这过程中用到的是我们自定义的一个Service，取名为/turtle_command ，这个Service的数据类型我们用到的是ROS中针对服务的标准的定义，叫做Trigger，相当于一个触发，当Server这一端收到触发信号之后，来控制海龟是否发送速度指令，同时返回一个Response告诉Client你的请求是否已经执行成功了，本例中Server这一端既包含了Server这一端的实现，同时也包含了一个topic的Publisher的实现，所以本例中的Server端包含两个内容。**

想要实现一个服务器端，需要以下操作：

1. 初始化ROS节点

2. 创建Server实例

3. 循环等待服务请求，进入回调函数

4. 在回调函数中完成服务功能的处理，并反馈应答数据

   ![ros14](D:\大二下\机器人\实验\Robotics\image\ros14.jpg)

### 自定义服务数据类型的编程实现

**client端要去发布显示某个人信息的请求，通过我们自定义的service数据把信息发出去，在server端我们就可以接收到这个请求，同时包含人的名字，年龄，性别等信息。通过日志显示出来，同时response反馈显示的结果，这期间用的service是我们自定义的/show_person,用到的数据类型是learning_service::Person**

**在message里面我们定义了.msg这样的文件，服务也是类似的，我们去定义.srv这样的文件，服务跟信息的区别是服务有反馈的内容，需要用三个横线将其分成两部分，三个横线以上时request的内容，三个横线以下是response的内容。**

![ros15](D:\大二下\机器人\实验\Robotics\image\ros15.jpg)
