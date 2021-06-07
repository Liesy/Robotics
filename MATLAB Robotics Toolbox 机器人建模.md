#### 山东大学 计算机科学与技术学院 自主智能系统与机器人 实验报告

#### MATLAB Robotics Toolbox 机器人建模

#### 智能19 李阳 201900170249

---

## D-H机器人建模方法分析

### 标准D-H

```matlab
L1=Link([0 0.2 1 pi/4 0],'standard');
L2=Link([0 0.2 1 pi/4 0],'standard');
L3=Link([0 0 0.5 pi/4 0],'standard');
robot=SerialLink([L1 L2 L3]);%建立连杆机器人
robot.plot([0 0 0]) %显示并赋值三个theta变量均为0
```

<img src="D:\大二下\机器人\实验\Robotics\image\5.10.6.jpg" alt="5.10.6" style="zoom:50%;" />

### 改进D-H

```matlab
L1=Link([0 0.2 1 pi/4 0],'modified');
L2=Link([0 0.2 1 pi/4 0],'modified');
L3=Link([0 0 0.5 pi/4 0],'modified');
robot=SerialLink([L1 L2 L3]);%建立连杆机器人
robot.plot([0 0 0]) %显示并赋值三个theta变量均为0
```

<img src="D:\大二下\机器人\实验\Robotics\image\5.10.7.jpg" alt="5.10.7" style="zoom:50%;" />

## 连杆Link类

- 创建一个连杆，需要用到 $Link()$ 函数，该函数可以根据输入的参数：关节角、连杆偏距、连杆长度、连杆角等产生一个 $Link$ 对象。

- $Link$ 对象包含了连杆的各种属性：运动学参数、惯性张量、电机、传递矩阵等。

- $Link()$ 函数的用法为：

  $L1=Link([0\quad 0.128\quad 0\quad -pi/2])$ 其中括号内输入的是参数，返回的 $L1$ 是对象。

## 机械臂Seriallink类

 **$Seriallink$ 的类函数较多，包括显示机器人、运动学、逆运动学、雅可比等，用的最多的是 $Seriallink()$ 和 $plot()$** 

### 定义一个三轴机械臂

```matlab
L1=Link([pi/4 0 0 0 0],'modified');
L2=Link([pi/2 0.2 0.1 0 0],'modified');
L3=Link([0 0.1 0.2 0 0],'modified');
robot=SerialLink([L1 L2 L3]);
robot.display();
theta=[0 0 0];
robot.plot(theta);
```

<img src="D:\大二下\机器人\实验\Robotics\image\5.10.8.jpg" alt="5.10.8" style="zoom:50%;" />

### 定义一个六轴机械臂

```matlab
L1=Link('d',0,'a',0,'alpha',pi/2);
L2=Link('d',0,'a',0.5,'alpha',0,'offset',pi/2);
L3=Link('d',0,'a',0,'alpha',pi/2,'offset',pi/4);
L4=Link('d',1,'a',0,'alpha',-pi/2);
L5=Link('d',0,'a',0,'alpha',pi/2);
L6=Link('d',1,'a',0,'alpha',0);
robot=SerialLink([L1 L2 L3 L4 L5 L6]);
robot.display();
theta=[0 0 0 0 0 0];
robot.plot(theta);
```

<img src="D:\大二下\机器人\实验\Robotics\image\5.10.9.jpg" alt="5.10.9" style="zoom:50%;" />

### 机器人示教

```matlab
L1=Link([0 0.4 0.025 pi/2 0]);
L2=Link([pi/2 0 0.56 pi/2 0]);
L3=Link([0 0 0.035 pi/2 0]);
L4=Link([0 0.515 0 pi/2 0]);
L5=Link([pi 0 0 pi/2 0]);
L6=Link([0 0.08 0 0 0]);
robot=SerialLink([L1 L2 L3 L4 L5 L6],'name','man');
robot.plot([0 pi/2 0 0 pi 0]);
robot.display();
teach(robot);
```

<img src="D:\大二下\机器人\实验\Robotics\image\5.10.10.jpg" alt="5.10.10" style="zoom:50%;" />

## 本章实验内容

**为教材中P81 习题2.33的机器人建模，并用图展示出建模结果。**

```matlab
%教材P81 习题2.33
L1=Link('d',0,'a',0,'alpha',-pi/2);
L2=Link('d',6,'a',15,'alpha',0);
L3=Link('d',0,'a',1,'alpha',-pi/2);
L4=Link('d',18,'a',0,'alpha',pi/2);
L5=Link('d',0,'a',0,'alpha',-pi/2);
L6=Link('d',0,'a',0,'alpha',0);
robot=SerialLink([L1 L2 L3 L4 L5 L6],'name','2.33');
robot.plot([0 pi/4 -pi/3 0 -pi/4 0]);% theta3的数值略有改动
robot.display();
```

<img src="D:\大二下\机器人\实验\Robotics\image\2.33.jpg" alt="2.33" style="zoom:50%;" />
