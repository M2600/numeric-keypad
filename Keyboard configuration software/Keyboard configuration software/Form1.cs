﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
using System.IO.Ports;
using System.Runtime.InteropServices;
using System.Diagnostics;
using System.Timers;


namespace Keyboard_configuration_software
{
    
    public partial class Form1 : Form
    {
        
        Form2 form2 = new Form2();
        Form3 form3 = new Form3();
        public static Form1 _form1Instance;

        NotifyIcon notifyIcon;

        [DllImport("user32.dll")]
        public static extern IntPtr GetForegroundWindow();

        [DllImport("user32.dll", EntryPoint = "GetWindowText", CharSet = CharSet.Auto)]
        public static extern int GetWindowText(IntPtr hWnd, StringBuilder lpString, int nMaxCount);

        
        [DllImport("user32.dll")]
        public static extern int GetWindowThreadProcessId(IntPtr hWnd, out int lpdwProcessId);

        private System.Timers.Timer _timer;
        private string appname = "a" ;
        public List<string> Gamelists = new List<string> (10){"Apex Legends", "Apex Legends", "Apex Legends", "Apex Legends", "Apex Legends", "Apex Legends", "Apex Legends", "Apex Legends", "Apex Legends", "Apex Legends" };
        public List<string> Codinglists = new List<string>(10) { "Arduino", "Arduino", "Arduino", "Arduino", "Arduino", "Arduino", "Arduino", "Arduino", "Arduino", "Arduino" };

        private string sendmessage = "0";
        public bool serialPortOpen = true;
        
        public static Form1 Form1Instance
        {
            get
            {
                return _form1Instance;
            }
            set
            {
                _form1Instance = value;
            }
        }
        public  SerialPort serialport1
        {
            get
            {
                return serialPort1;
            }
            set
            {
                serialPort1 = value;
            }
        }
        public TextBox TextBox
        {
            get
            {
                return textBox1;
            }
            set
            {
                textBox1 = value;
            }
        }

        public Form1()
        {
            InitializeComponent();

            this.ShowInTaskbar = true;
            this.setComponents();

        }
        private void setComponents()
        {
            notifyIcon = new NotifyIcon();
            // アイコンの設定
            notifyIcon.Icon = new Icon(@"E:\M260\Documents\GitHub\numeric-keypad\Keyboard configuration software\Keyboard configuration software\colorKeyboard.ico");
            // アイコンを表示する
            notifyIcon.Visible = true;
            // アイコンにマウスポインタを合わせたときのテキスト
            notifyIcon.Text = "KeyboardConfiguration";
            ContextMenuStrip contextMenuStrip = new ContextMenuStrip();
            ToolStripMenuItem toolStripMenuItem = new ToolStripMenuItem();
            toolStripMenuItem.Text = " & 終了";
            toolStripMenuItem.Click += ToolStripMenuItem_Click;
            contextMenuStrip.Items.Add(toolStripMenuItem);
            notifyIcon.ContextMenuStrip = contextMenuStrip;

            notifyIcon.Click += NotifyIcon_Click;
        }
        private void ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            notifyIcon.Dispose();
            Application.Exit();
        }
        private void NotifyIcon_Click(object sender, EventArgs e)
        {
            // Formの表示/非表示を反転
            this.Visible = !this.Visible;
            this.ShowInTaskbar = this.Visible;
        }


        private void Form1_Load(object sender, EventArgs e)
        {
            Form1._form1Instance = this;
            Form2 form2 = new Form2();
            form2.Hide();
            form2.Left = this.Location.X + 20;
            form2.Top = this.Location.Y + 20;

            //ユーザーがサイズを変更できないようにする
            //最大化、最小化はできる
            this.FormBorderStyle = FormBorderStyle.FixedSingle;

            StringBuilder sb = new StringBuilder(65535);//65535に特に意味はない
            GetWindowText(GetForegroundWindow(), sb, 65535);
            Console.WriteLine(sb);

            //serialPort1.Close();
            serialPort1.PortName = Properties.Settings.Default.SerialPort;
            serialPort1.WriteTimeout = 500;
            //serialPort1.Open();
            
            Invoke((MethodInvoker)(() =>    // 受信用スレッドから切り替えてデータを書き込む
            {
                textBox1.AppendText("Port opened to " + Form1.Form1Instance.serialport1.PortName + "\r\n");

            }));
            Console.WriteLine("Port opened to " + Form1.Form1Instance.serialport1.PortName);

            Gamelists[0] = Properties.Settings.Default.Gamelists0;
            Gamelists[1] = Properties.Settings.Default.Gamelists1;
            Gamelists[2] = Properties.Settings.Default.Gamelists2;
            Gamelists[3] = Properties.Settings.Default.Gamelists3;
            Gamelists[4] = Properties.Settings.Default.Gamelists4;
            Gamelists[5] = Properties.Settings.Default.Gamelists5;
            Gamelists[6] = Properties.Settings.Default.Gamelists6;
            Gamelists[7] = Properties.Settings.Default.Gamelists7;
            Gamelists[8] = Properties.Settings.Default.Gamelists8;
            Gamelists[9] = Properties.Settings.Default.Gamelists9;
            //Gamelists[10] = Properties.Settings.Default.Gamelists10;
            Codinglists[0] = Properties.Settings.Default.Codinglists0;
            Codinglists[1] = Properties.Settings.Default.Codinglists1;
            Codinglists[2] = Properties.Settings.Default.Codinglists2;
            Codinglists[3] = Properties.Settings.Default.Codinglists3;
            Codinglists[4] = Properties.Settings.Default.Codinglists4;
            Codinglists[5] = Properties.Settings.Default.Codinglists5;
            Codinglists[6] = Properties.Settings.Default.Codinglists6;
            Codinglists[7] = Properties.Settings.Default.Codinglists7;
            Codinglists[8] = Properties.Settings.Default.Codinglists8;
            Codinglists[9] = Properties.Settings.Default.Codinglists9;
            //Gamelists[10] = Properties.Settings.Default.Codinglists10;


            for (int i = 0; i < Math.Max(Gamelists.Count,Codinglists.Count); i++)
            {
                Invoke((MethodInvoker)(() =>    // 受信用スレッドから切り替えてデータを書き込む
                {
                    textBox2.AppendText(Gamelists[i] + "\r\n");
                    textBox3.AppendText(Codinglists[i] + "\r\n");
                }));
            }



            _timer = new System.Timers.Timer(1000.0 / 10.0); // in milliseconds - you might have to play with this value to throttle your framerate depending on how involved your update and render code is 
            _timer.Elapsed += TimerElapsed;
            _timer.Start();

            Console.WriteLine("form1Loaded");
        }

        

       


        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            
        }

        private void tabPage1_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
        private void button1_Click_1(object sender, EventArgs e)
        {
            form2.Left = this.Location.X + 20;
            form2.Top = this.Location.Y + 20;
            form2.Show();
            form2.Activate();
            Console.WriteLine("form2 showed");
        }



        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            /*Console.WriteLine("serialPort1_DataReceived");
            try
            {
                string data = serialPort1.ReadLine();	// ポートから文字列を受信する
                if (!string.IsNullOrEmpty(data))
                {
                    Console.WriteLine("isnullenpty");
                    Invoke((MethodInvoker)(() =>	// 受信用スレッドから切り替えてデータを書き込む
                    {
                        textBox1.AppendText(data + "\r\n");	// ラベルを受信した文字列へ変更
                        Thread.Sleep(1);
                        Console.WriteLine("invoke");
                    }));
                    Console.WriteLine("triedl");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                Console.WriteLine("catched");
            }*/
        }

        private void textBox1_TextChanged_1(object sender, EventArgs e)
        {

        }
        private void TimerElapsed(object sender, ElapsedEventArgs e)
        {
            StringBuilder sb = new StringBuilder(65535);//65535に特に意味はない
            GetWindowText(GetForegroundWindow(), sb, 65535);
            Console.WriteLine(sb);
            bool send = false;
            
            if(appname != sb.ToString() && IsHandleCreated)
            {
                Invoke((MethodInvoker)(() =>    // 受信用スレッドから切り替えてデータを書き込む
                {
                    textBox1.AppendText(sb.ToString() + "\r\n");
                    
                }));
                for(int i=0;i< Math.Max(Gamelists.Count, Codinglists.Count); i++)
                {
                    if (sb.ToString().Contains(Gamelists[i]))
                    {
                        Invoke((MethodInvoker)(() =>    // 受信用スレッドから切り替えてデータを書き込む
                        {
                            textBox1.AppendText("game" + "\r\n");
                            //if (!serialPort1.IsOpen)
                            //{
                            //    serialPort1.Open();
                            //}
                            sendSerialCommunication("G");
                            appname = sb.ToString();
                            send = true;
                        }));
                    }
                    else if (sb.ToString().Contains(Codinglists[i]))
                    {
                        Invoke((MethodInvoker)(() =>    // 受信用スレッドから切り替えてデータを書き込む
                        {
                            textBox1.AppendText("code" + "\r\n");
                            //if (!serialPort1.IsOpen)
                            //{
                            //    serialPort1.Open();
                            //}
                            sendSerialCommunication("C");
                            appname = sb.ToString();
                            send = true;
                            //serialport1.Close();
                        }));
                    }
                    
                }
                if(!send)
                {
                    Invoke((MethodInvoker)(() =>    // 受信用スレッドから切り替えてデータを書き込む
                    {
                        //textBox1.AppendText("other" + "\r\n");
                        //if(!serialPort1.IsOpen)
                        //{
                        //    serialPort1.Open();
                        //}
                        sendSerialCommunication("D");
                        appname = sb.ToString();
                        //if (serialPort1.IsOpen)
                        //{
                        //    serialPort1.Close();
                        //}
                    }));
                }
                
            }
                
            
            

        }
        private void sendSerialCommunication(string message)
        {
            if(sendmessage != message && serialPortOpen)
            {
                Invoke((MethodInvoker)(() =>    // 受信用スレッドから切り替えてデータを書き込む
                {
                    //if (!serialPort1.IsOpen)
                    //{
                        serialPort1.Open();
                    //}
                    serialPort1.Write(message);
                    textBox1.AppendText(message + "\r\n");
                    //if (serialPort1.IsOpen)
                    //{
                        serialPort1.Close();
                    //}
                }));
                
                Console.WriteLine("send " + message);
                sendmessage = message;
            }

        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (e.CloseReason == CloseReason.UserClosing)
            {
                e.Cancel = true;
            }

            this.Visible = !this.Visible;
            this.ShowInTaskbar = Visible;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < Math.Min(textBox2.Lines.Length, 10); i++)
            {
                Gamelists[i]=(textBox2.Lines[i]);
            }
            Properties.Settings.Default.Gamelists0 = Gamelists[0];
            Properties.Settings.Default.Gamelists1 = Gamelists[1];
            Properties.Settings.Default.Gamelists2 = Gamelists[2];
            Properties.Settings.Default.Gamelists3 = Gamelists[3];
            Properties.Settings.Default.Gamelists4 = Gamelists[4];
            Properties.Settings.Default.Gamelists5 = Gamelists[5];
            Properties.Settings.Default.Gamelists6 = Gamelists[6];
            Properties.Settings.Default.Gamelists7 = Gamelists[7];
            Properties.Settings.Default.Gamelists8 = Gamelists[8];
            Properties.Settings.Default.Gamelists9 = Gamelists[9];
            Properties.Settings.Default.Save();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < Math.Min(textBox3.Lines.Length,10); i++)
            {
                Codinglists[i]=(textBox3.Lines[i]);
            }
            Properties.Settings.Default.Codinglists0 = Gamelists[0];
            Properties.Settings.Default.Codinglists1 = Gamelists[1];
            Properties.Settings.Default.Codinglists2 = Gamelists[2];
            Properties.Settings.Default.Codinglists3 = Gamelists[3];
            Properties.Settings.Default.Codinglists4 = Gamelists[4];
            Properties.Settings.Default.Codinglists5 = Gamelists[5];
            Properties.Settings.Default.Codinglists6 = Gamelists[6];
            Properties.Settings.Default.Codinglists7 = Gamelists[7];
            Properties.Settings.Default.Codinglists8 = Gamelists[8];
            Properties.Settings.Default.Codinglists9 = Gamelists[9];
            Properties.Settings.Default.Save();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if(serialPortOpen)
            {
                serialPortOpen = false;
                Console.WriteLine("serialPortClosed.");
                textBox1.AppendText("PortClosed" + "\r\n");
                button4.Text = "PortOpen";
            }
            else
            {
                serialPortOpen = true;
                Console.WriteLine("serialPortOpened.");
                textBox1.AppendText("PortOpened" + "\r\n");
                button4.Text = "PortClose";
            }
            
        }
    }
}
