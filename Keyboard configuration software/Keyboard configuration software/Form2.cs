using System;
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

namespace Keyboard_configuration_software
{
    public partial class Form2 : Form
    {

        [DllImport("user32.dll")]
        public static extern IntPtr GetForegroundWindow();

        [DllImport("user32.dll", EntryPoint = "GetWindowText", CharSet = CharSet.Auto)]
        public static extern int GetWindowText(IntPtr hWnd, StringBuilder lpString, int nMaxCount);
        //Form1 form1 = new Form1();

       
        public static Form2 _form2Instance;

        public static Form2 Form2Instance
        {
            get
            {
                return _form2Instance;
            }
            set
            {
                _form2Instance = value;
            }
        }
        

        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            Form2._form2Instance = this;
            StringBuilder sb = new StringBuilder(65535);//65535に特に意味はない
            GetWindowText(GetForegroundWindow(), sb, 65535);
            Console.WriteLine(sb);

            //ユーザーがサイズを変更できないようにする
            //最大化、最小化はできる
            this.FormBorderStyle = FormBorderStyle.FixedSingle;
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
        private void setSerialPort(object sender, EventArgs e)
        {
            if(comboBox1.SelectedItem != null)
            {
                Form1.Form1Instance.serialport1.Close();
                Form1.Form1Instance.serialport1.PortName = comboBox1.SelectedItem.ToString();
                Form1.Form1Instance.serialport1.Open();
                Form1.Form1Instance.TextBox.AppendText("Port opened to " + Form1.Form1Instance.serialport1.PortName + "\r\n");
                Console.WriteLine("Port opened to " + Form1.Form1Instance.serialport1.PortName);
                Properties.Settings.Default.SerialPort = Form1.Form1Instance.serialport1.PortName;
                Properties.Settings.Default.Save();
                label2.Text = " ";
                this.Hide();
            }
            else
            {
                Form1.Form1Instance.TextBox.AppendText("The port number was not set. " + "\r\n");
                label2.Text = "Please select a port number.";
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            
        }
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (e.CloseReason == CloseReason.UserClosing)
            {
                e.Cancel = true;
            }
            label2.Text = " ";

            this.Hide();
        }
    }
}
