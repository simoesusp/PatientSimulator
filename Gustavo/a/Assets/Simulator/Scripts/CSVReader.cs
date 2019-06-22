using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CSVReader : MonoBehaviour {

    public List<Remedio> remedios = new List<Remedio>();

	// Use this for initialization
	void Start () {

        TextAsset dadosremedios = Resources.Load<TextAsset>("ListaRemedios");
        
        string[] data = dadosremedios.text.Split(new char[] { '\n' });
        for( int i = 1; i <data.Length - 1; i++)
        {
            string[] row = data[i].Split(new char[] { ',' });
            Remedio r = new Remedio();

            //int.TryParse(row[0], out r.id);
            r.nome = row[0];
     
            int.TryParse(row[1], out r.min);
            int.TryParse(row[2], out r.max);
            float.TryParse(row[3], out r.pressao);
            float.TryParse(row[4], out r.temp);

            float.TryParse(row[5], out r.bpm);



            remedios.Add(r);
            //Debug.Log(remedios.Count);


        }


    }
	
	// Update is called once per frame
	void Update () {
		
	}
}
