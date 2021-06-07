#### 山东大学 计算机科学与技术学院 自主智能系统与机器人 实验报告

#### MATLAB Robotics Toolbox 简单应用——坐标系变换

#### 智能19 李阳 201900170249

---

## 旋转变换

- 在机器人工具箱中，可以用 $rotx(\theta),roty(\theta),rotz(\theta)$ 来计算旋转 $\theta$ 的旋转矩阵，默认单位为弧度。
- 可以用 $trplot(),tranimate()$ 实现坐标旋转可视化。

**例3.2**

<img src="D:\大二下\机器人\实验\Robotics\image\3.2.jpg" alt="3.2" style="zoom:50%;" />

## 平移变换

- $transl()$ 创建平移变换矩阵。
- $transl()$ 获取一个矩阵中的平移分量。

## 矩阵分解

- $R=t2r(T)$ 用于获取齐次变换矩阵 $T$ 中的正交旋转矩阵分量，如果 $T$ 是一个 $4\times4$ 的旋转矩阵，则 $R$ 是一个 $3\times3$ 的矩阵。
- $T=r2t(R)$ 可将旋转矩阵转换为齐次矩阵，获取一个正交旋转矩阵 $R$ 等价的具有零平移分量的齐次变换矩阵。如果 $R$ 是一个 $3\times3$ 的矩阵，则  $T$ 是一个 $4\times4$ 的矩阵。如果 $R$ 是一个 $2\times2$ 的矩阵，则  $T$ 是一个 $3\times3$ 的矩阵。

**例3.7**

<img src="D:\大二下\机器人\实验\Robotics\image\3.7.jpg" alt="3.7" style="zoom:50%;" />

## 本章实训内容

### 教材P34 例2.6

```matlab
T0=[0.527 -0.574 0.628;0.396 0.819 0.439;-0.766 0 0.643];
F=transl(5,3,8)*r2t(T0)
T1=transl(0,10,5);
Fn=T1*F
trplot(F,'frame','o','color','b');
axis([0 15 0 15 0 15]);
hold on
tranimate(F,Fn,'frame','n','color','r')
hold off
```

<img src="D:\大二下\机器人\实验\Robotics\image\2.6.jpg" alt="2.6" style="zoom:50%;" />

### 教材P36 例2.7

```matlab
p1=[2;3;4;1]
T0=transl(0,0,0);
T=trotx(pi/2);
p2=T*p1
trplot(T0,'frame','o','color','b');
axis([-3 3 -3 3 -3 3]);
hold on
tranimate(T0,T,'frame,','n','color','r')
```

<img src="D:\大二下\机器人\实验\Robotics\image\5.10.3.jpg" alt="5.10.3" style="zoom:50%;" />

### 教材P38 例2.9

```matlab
p1=[7;3;1;1];
T0=transl(0,0,0);
T1=trotz(pi/2);
T2=transl(4,-3,7);
T3=troty(pi/2);
T=T3*T2*T1;
p2=T*p1
trplot(T0,'frame','o','color','r');
axis([-3 10 -3 5 -5 3])
hold on
tranimate(T0,T,'frame','n','color','b')
```

<img src="D:\大二下\机器人\实验\Robotics\image\5.10.4.jpg" alt="5.10.4" style="zoom:50%;" />

### 教材P40 例2.11

```matlab
T0=transl(0,0,0);
T1=trotx(pi/2);
T2=transl(0,0,3);
T3=trotz(pi/2);
T4=transl(0,5,0);
T=T3*T1*T2*T4;
p1=[1;5;4;1]
p2=T*p1
trplot(T0,'frame','o','color','r');
axis([-3 10 -3 5 -5 10])
hold on
tranimate(T0,T,'frame','n','color','b')
```

<img src="D:\大二下\机器人\实验\Robotics\image\5.10.5.jpg" alt="5.10.5" style="zoom:50%;" />
