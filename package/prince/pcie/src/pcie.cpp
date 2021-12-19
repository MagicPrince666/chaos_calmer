#include <stdio.h>
#include <ctype.h>
#include <string.h>
 
#include <pci/pci.h>
#include <pciaccess.h>
 
int config_space_read(int vendor_id, int device_id, int print){
	
	int i = 0;
	int ret = 0;
	struct pci_access * myaccess;
	struct pci_dev * mydev;
	
	myaccess = pci_alloc();
	
	pci_init(myaccess);
	
	pci_scan_bus(myaccess);		
	
	for (mydev = myaccess->devices; mydev; mydev = mydev->next){
		
		pci_fill_info(mydev, PCI_FILL_IDENT | PCI_FILL_BASES | PCI_FILL_CLASS);
		
		if(mydev->vendor_id == vendor_id && mydev->device_id == device_id){
			
			if (print == 1){
				
				printf("Configuration space content:\n");
			
				for (i = 0; i < 64; i++) {
 
					ret = pci_read_byte(mydev, i);
					
					printf("%d: %02x \t", i, ret);
					
					if(i%4 == 3 ){
						
						printf("\n");
					}
				}
			}else{
				
				for (i = 0; i < 64; i++) {
 
					pci_read_byte(mydev, i);					
			    }
			}		
			
			return 1;
		}
	}
	
	pci_free_dev(mydev);
 
    pci_cleanup(myaccess);
 
    return 0;
}
 
int config_space_write(int vendor_id, int device_id,  int position, unsigned int data[],int length){
	
	int i = 0;
	struct pci_access * myaccess;
	struct pci_dev * mydev;
	
	myaccess = pci_alloc();
	
	pci_init(myaccess);
	
	pci_scan_bus(myaccess);		
 
	for (mydev = myaccess->devices; mydev; mydev = mydev->next){
		
		pci_fill_info(mydev, PCI_FILL_IDENT | PCI_FILL_BASES | PCI_FILL_CLASS);
		
		if(mydev->vendor_id == vendor_id && mydev->device_id == device_id){
			
			for(i = 0; i < length; i++, position++){				
	
				pci_write_byte(mydev, position, data[i]);
 
			}
			
			return 1;
			
		}
		
	}
	
	pci_free_dev(mydev);
 
    pci_cleanup(myaccess);
	
	return 0;
}
 
int main(int argc, char* argv[]){
 
	int vendor_id ;
	int device_id ;
	int choose ;
	int num ;
	int length ;
	unsigned int data[256] = {0};
	int position = 0;
	int i = 0 ;
	int flag = 1;
	FILE *fp;
	int print = 0;
	
	printf("Please input vid & pid(for example:8086 1c02):");	
	scanf("%x%x", &vendor_id, &device_id);
			
	printf("\t\t 1-Configuration space read test\t\t 2-Configuration space write test \n please choose:");
	scanf("%d", &choose);
	
	switch(choose){
		
		case 1:{
			
			printf("Enter the number of times :");
			scanf("%d", &num);
			
			print = 1;
			config_space_read(vendor_id, device_id, print);	
			
			print = 0;
			for(i = 1; i < num; i++){
 
				config_space_read(vendor_id, device_id, print);		
			}
 
			printf("Read PCIE configuration space %d times\n", num);
			
			break;
		}
		
		case 2:{
		
			printf("Enter the number of times:");
			scanf("%d", &num);
 
			printf("Enter the starting position (decimal):");
			scanf("%d", &position);
			
			printf("Enter the length:");
			scanf("%d", &length);
			
			fp = fopen("in.txt", "r");
			
			if (fp == NULL){
				
				printf("Can't open file!\n");
				
				return -1;
			}
				
			for(i = 0; i< length; i++){
				
				fscanf(fp, "%x", &data[i]);
			}
			
			printf("The data is :\n");
			
			for(i = 0; i< length; i++){
				
				printf("%x \t", data[i]);
				
				if (i%4 == 3){
				
					printf("\n");
				}
					
			}		
			
			printf("\n");
			
			fclose(fp);
						
			for(i = 0; i < num; i++){
			
				flag = config_space_write(vendor_id, device_id, position, data, length);	
				
				if(flag == 0){
 
					printf("This device not exist!\n");
					
				}					
			}				
			
			printf("Write PCIE configuration space %d times\n", num);
 
			print = 1;			
			config_space_read(vendor_id, device_id, print);			
			
			break;
		}
	}
	
	return 0;
}
