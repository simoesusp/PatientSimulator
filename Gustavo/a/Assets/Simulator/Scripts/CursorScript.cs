using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CursorScript : MonoBehaviour {

    public bool flag = false;
    public GameObject cursor;
    //public GameObject script;
	// Use this for initialization
	void Start () {
        
        
    }
	
	// Update is called once per frame
	void Update () {

        if (Input.GetKeyDown(KeyCode.G)|| Input.GetKeyDown(KeyCode.Alpha2))
        {
            if (!flag)
            {
                GetComponent<UnityStandardAssets.Characters.FirstPerson.FirstPersonController>().enabled = false;
                Cursor.lockState = CursorLockMode.None;
                Cursor.visible = (true);
                cursor.SetActive(false);
                flag = true;
            }
            else
            {
                GetComponent<UnityStandardAssets.Characters.FirstPerson.FirstPersonController>().enabled = true;
                Cursor.lockState = CursorLockMode.Locked;
                Cursor.visible = (false);
                cursor.SetActive(true);
                flag = false;
            }
        }
    }
}
