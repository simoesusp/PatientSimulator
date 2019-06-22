using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class zoomcamera : MonoBehaviour {

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {

        if (Input.mouseScrollDelta.y > 0 && GetComponent<Camera>().fieldOfView > 1)
        {
            GetComponent<Camera>().fieldOfView--;
            //GetComponent<Transform>().position = new Vector3(transform.position.x, transform.position.y-.3f, transform.position.z-.2f);
        }
            
        if (Input.mouseScrollDelta.y < 0 && GetComponent<Camera>().fieldOfView < 60)
        {
            GetComponent<Camera>().fieldOfView++;
        }
            

    }
}
