using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PacienteAnimator : MonoBehaviour {

    // Use this for initialization
    Animator anim;
    public GameObject Paciente;
    public GameObject hospbed;
    public GameObject organs;
    
    //int sitHash = Animator.StringToHash("mixamo_com");
	void Start () {
        anim = GetComponent<Animator>();
	}
	
	// Update is called once per frame
	void Update () {
		
       /*     if (Input.GetKeyDown(KeyCode.Z))
        {
            anim.SetTrigger("IsSitting");
           // Vector3 targetDir;
            //targetDir = new Vector3(transform.position.x - this.transform.position.x, 0f, transform.position.z - this.transform.position.z);
            //Quaternion rot = Quaternion.LookRotation(targetDir);
            //this.transform.rotation = Quaternion.Slerp(this.transform.rotation, rot, 0.05f);
            //this.transform.Translate(Vector3.forward * 0.01f);

            //this.transform.rotation = hospbed.transform.rotation;
            //this.transform.rotation = hospbed.transform.rotation;
            //transform.Rotate(Vector3.up, Time.deltaTime);
            //this.transform.Rotate(Time.deltaTime, 0, 0);
            //this.transform.rotation = 90.0f;
            //orgnas = 
        }
        if (Input.GetKeyDown(KeyCode.X))
        {
            anim.SetTrigger("IsLaying");

        }*/


    }
}
