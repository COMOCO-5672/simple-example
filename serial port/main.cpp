//#include "StdAfx.h"
#include "SerialPort.h"
using namespace std;
int _tmain(int argc, _TCHAR *argv[])
{
    CSerialPort mySerialPort; //首先将之前定义的类实例化
    int length = 8;           //定义传输的长度

    unsigned char *temp = new unsigned char[8]; //动态创建一个数组

    if (!mySerialPort.InitPort(3, CBR_19200, 'N', 8, 1, EV_RXCHAR)) //是否打开串口，3就是你外设连接电脑的com口，可以在设备管理器查看，然后更改这个参数
    {
        std::cout << "initPort fail !" << std::endl;
    }
    else
    {
        std::cout << "initPort success !" << std::endl;
    }
    if (!mySerialPort.OpenListenThread()) //是否打开监听线程，开启线程用来传输返回值
    {
        std::cout << "OpenListenThread fail !" << std::endl;
    }
    else
    {
        std::cout << "OpenListenThread success !" << std::endl;
    }

    temp[0] = 03;
    temp[1] = 85;
    temp[2] = 04;
    temp[3] = 00;
    temp[4] = 00;
    temp[5] = 00;
    temp[6] = 11;
    temp[7] = 03;
    cout << mySerialPort.WriteData(temp, 8) << endl; //这个函数就是给串口发送数据的函数，temp就是要发送的数组。
    cout << mySerialPort.GetBytesInCOM() << endl;    //这个函数就是显示返回值函数
    // delete temp[];
    system("pause");
    return 0;
}