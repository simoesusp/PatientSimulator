using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PacienteParametros : MonoBehaviour {

    public GameObject PainelPaciente;
    public int pressao;
    public int pressaosys = 120;
    public int pressaodias = 80;
    public float temp;
    public int bpm;
    public int resp;
    public Slider bpmslider;

    // Use this for initialization
    void Start () {
        PainelPaciente.GetComponent<CanvasGroup>().alpha = 0f;
        PainelPaciente.GetComponent<CanvasGroup>().blocksRaycasts = false;

    }
	
	// Update is called once per frame
	void Update () {

        if (Input.GetKeyDown(KeyCode.K))
        {
            
            PainelPaciente.SetActive(true);
            PainelPaciente.GetComponent<CanvasGroup>().alpha = 1f;
            PainelPaciente.GetComponent<CanvasGroup>().blocksRaycasts = true;
        }
        if (Input.GetKeyDown(KeyCode.L))
        {
            //PainelPaciente.SetActive(false);
            PainelPaciente.GetComponent<CanvasGroup>().alpha = 0f;
            PainelPaciente.GetComponent<CanvasGroup>().blocksRaycasts = false;

        }

        

    }
    public void adjustBpm(float newbpm)
    {
        bpm = (int)newbpm;
    }
    public void adjustSys(float newsys)
    {
        pressaosys = (int)newsys;
    }
    public void adjustDias(float newdias)
    {
        pressaodias = (int)newdias;
    }
    public void adjustTemp(float newtemp)
    {
        temp = newtemp;
    }
    public void adjustResp(float newresp)
    {
        resp = (int)newresp;
    }

    public void moveSlider(float num)
    {
        bpmslider.value = 1;
    }

}
