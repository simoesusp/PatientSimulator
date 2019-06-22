using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class RemedioSpecs : MonoBehaviour {

    public InputField inputField;
    public Slider slider;
    public Button botao;

    public GameObject parametros;
    public GameObject membro;
    public TCPTestServer temp;

    public Remedio remedio;
    public int bpmc;
    public int pressaoc;
    public float tempc;

    public bool flag;


    public string messageresp;
    public string letraresp;
    //public void SliderUpdate(float value) { inputField.text = value.ToString(); }

    //public void InputFieldUpdate(string text) { slider.value = System.Convert.ToSingle(text); }



    public void UpdateValueFromFloat(float value)
    {
        //Debug.Log("float value changed: " + value);
        if (slider) { slider.value = value; }
        if (inputField) { inputField.text = value.ToString(); }
    }

    public void UpdateValueFromString(string value)
    {
        //Debug.Log("string value changed: " + value);
        if (slider) { slider.value = float.Parse(value); }
        if (inputField) { inputField.text = value; }
    }
    public void onButtonClick()
    {

        bpmc = (int)(slider.value * remedio.bpm);
        pressaoc =(int)( slider.value * remedio.pressao);
        tempc = slider.value * remedio.temp;
        print(slider.value);
        print(bpmc);
        print(pressaoc);
        print(tempc);
        //parametros.GetComponent<PacienteParametros>().bpm = parametros.GetComponent<PacienteParametros>().bpm  + bpmc;
        //parametros.GetComponent<PacienteParametros>().pressaosys = parametros.GetComponent<PacienteParametros>().pressaosys + pressaoc;
        //parametros.GetComponent<PacienteParametros>().pressaodias = parametros.GetComponent<PacienteParametros>().pressaodias + pressaoc;
        //parametros.GetComponent<PacienteParametros>().temp = parametros.GetComponent<PacienteParametros>().temp + tempc;
        membro.GetComponent<Membros>().bpm = parametros.GetComponent<PacienteParametros>().bpm + bpmc;
        membro.GetComponent<Membros>().pressaosys = parametros.GetComponent<PacienteParametros>().pressaosys + pressaoc;
        membro.GetComponent<Membros>().pressaodias = parametros.GetComponent<PacienteParametros>().pressaodias + pressaoc;
        membro.GetComponent<Membros>().temp = parametros.GetComponent<PacienteParametros>().temp + tempc;
        membro.GetComponent<Membros>().aux = true;


        //messageresp = bpmc.ToString() + pressaoc.ToString() + tempc.ToString();

        if (bpmc != 0)
        {
            letraresp = "c";
            messageresp = bpmc.ToString();

        }
        //if (pressaoc != 0)
        //    messageresp = messageresp + pressaoc.ToString();
        //if (tempc != 0)
        //    messageresp = messageresp + tempc.ToString();


        Debug.Log(messageresp);
        Debug.Log(letraresp + "=====letra");
        //temp.GetComponent<TCPTestServer>().msg = messageresp;
        parametros.GetComponent<TCPTestServer>().msg = messageresp;
        parametros.GetComponent<TCPTestServer>().letra = letraresp;
        //TCPTestServer.Sendmessage();
        //temp.GetComponent<TCPTestServer>().SendMessage();
        //temp.SendMessage();
        //parametros.SendMessage();
        parametros.GetComponent<TCPTestServer>().SendMessage1();
        parametros.GetComponent<TCPTestServer>().SendMessage();
        
    }
    // Use this for initialization
    void Start () {

        parametros = GameObject.Find("Canvas/EspecPaciente");
        membro = GameObject.Find("Corpo/Cylinder");
        botao.GetComponent<Button>().onClick.AddListener(() => onButtonClick());
    }
	
	// Update is called once per frame
	void Update () {
		
	}
}
