using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Membros : MonoBehaviour {

    public int pressaosys = 120;
    public int pressaodias = 80;
    public float temp;
    public int bpm;
    public int resp;

    public GameObject parametros;
    public bool aux;
    public GameObject RemedioSpecs;
    public Behaviour halo;
    // Use this for initialization
    void Start () {
        parametros = GameObject.Find("Canvas/EspecPaciente");
    }
	
	// Update is called once per frame
	void Update () {
        //flag = RemedioSpecs.GetComponent<RemedioSpecs>().flag;

    }

    void OnMouseDown()
    {
        halo.enabled = true;
        if (aux)
        {

            parametros.GetComponent<PacienteParametros>().bpm =  bpm;
            parametros.GetComponent<PacienteParametros>().pressaosys =  pressaosys;
            parametros.GetComponent<PacienteParametros>().pressaodias = pressaodias;
            parametros.GetComponent<PacienteParametros>().temp = temp;
            aux = false;
        }
    }

}
