using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel; 

namespace CSharpTest
{
    class ViewModel : INotifyPropertyChanged 
    {
        // This class implements INotifyPropertyChanged 
        // to support one-way and two-way bindings 
        // (such that the UI element updates when the source 
        // has been changed dynamically) 
        private string data; 
            
        // Declare the event 
        public event PropertyChangedEventHandler PropertyChanged; 
            
        public ViewModel() { }

        public ViewModel(string value) 
        {
            this.data = value; 
        }

        public string UpdateData 
        { 
            get 
            {
                return data; 
            } 
                
            set 
            {
                data = value; 
                    
                // Call OnPropertyChanged whenever the property is updated 
                OnPropertyChanged("UpdateData"); 
            } 
        } 
            
        // Create the OnPropertyChanged method to raise the event
        protected void OnPropertyChanged(string data) 
        { 
            PropertyChangedEventHandler handler = PropertyChanged; 
                
            if (handler != null) 
            {
                handler(this, new PropertyChangedEventArgs(data)); 
            } 
        } 
        
    }
}
