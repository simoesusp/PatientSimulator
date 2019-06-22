using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bracadeira : MonoBehaviour {

    public Behaviour sound;

    public GameObject pacientep;
    public GameObject Esfigm1;
    public GameObject Tela;
    public int flag;
    public int current;
    public int isys = 0;
    public int idia = 0;
    public int min;
    public int max;
    bool click;
    float temps;
    float lastStep, timeBetweenSteps = 0.5f;
    // Use this for initialization
    void decreasep()
    {
        temps = Time.time;
        click = true;
            if (Time.time - lastStep > timeBetweenSteps)
            {
                current = current - 1;
                lastStep = Time.time;
            //Do step
        }
        
    }
    void increasep()
    {
        temps = Time.time;
        click = true;
        if (Time.time - lastStep > timeBetweenSteps)
        {
            current = current + 1;
            lastStep = Time.time;
            //Do step
        }

    }

    void Start()
    {
        max = pacientep.GetComponent<PacienteParametros>().pressaosys;
        min = pacientep.GetComponent<PacienteParametros>().pressaodias;
        sound = (Behaviour)gameObject.GetComponent("AudioSource");
      
        flag = Tela.GetComponent<Tela>().min;

        gameObject.SetActive(false);
        sound.enabled = false;

    }

    // Update is called once per frame
    void Update()
    {
        max = pacientep.GetComponent<PacienteParametros>().pressaosys;
        min = pacientep.GetComponent<PacienteParametros>().pressaodias;
        if (current <= max && current >= min)
        {
            sound.enabled = true;
        }
        else
            sound.enabled = false;
       

    }
    void OnMouseDown()
    {
        current = current + 10;
        lastStep = Time.time;
    }
    void OnMouseUp()
    {
        


    }
    
    void OnMouseEnter()
    {
        


    }
    private void OnMouseOver()
    {
        if (Input.GetMouseButtonDown(1))
        {
            decreasep();
            idia = current;
        }
        if (Input.GetMouseButton(1))
        {
            decreasep();
            idia = current;
        }
        if (Input.GetMouseButton(0))
        {
            decreasep();
            isys = current;
            idia = current;
        }
        else
            print("Released");
    }
    void OnMouseExit()
    {
        
    }
}
