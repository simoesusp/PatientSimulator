using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Tela : MonoBehaviour {

    public GameObject Bracadeira;
    public GameObject paciente;
    public Text sys;
    public Text dia;
    public int current;
    public int isys = 0;
    public int idia = 0;
    public int min;
    public int max;
    // Use this for initialization
    void Start () {
        max = paciente.GetComponent<PacienteParametros>().pressaosys;
        min = paciente.GetComponent<PacienteParametros>().pressaodias;

        sys.text = isys.ToString();
        dia.text = idia.ToString();
        
    }
	
	// Update is called once per frame
	void Update () {
        isys = Bracadeira.GetComponent<Bracadeira>().isys;
        idia = Bracadeira.GetComponent<Bracadeira>().idia;
        sys.text = isys.ToString();
        dia.text = idia.ToString();
    }
}
