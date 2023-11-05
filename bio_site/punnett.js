function CalculateF1() {
    let p1Genotype = document.getElementById("P1").value;
    let p2Genotype = document.getElementById("P2").value;
    let dom = document.getElementById("DomType").value;
    
    let zeroCheck = p1Genotype.length !=0 && p2Genotype.length != 0;
    let lengthCheck = p1Genotype.length % 2 == 0;
    let inputMatch = p1Genotype.length == p2Genotype.length;
    let locusCheck = true;

    if (zeroCheck && lengthCheck && inputMatch) {
        locusCheck = LocusCheck(p1Genotype, p2Genotype);
    }

    if (zeroCheck && lengthCheck && inputMatch && locusCheck) {
        let singleAlleles = CombineAlleles(p1Genotype, p2Genotype);
        let F1 = F1Genotypes(singleAlleles);

        DisplayResults(F1, dom);
    }
    else {
        let errorMsg = "";
        if (!lengthCheck || !zeroCheck) {errorMsg = "Improper allele length"}
        else if (!inputMatch) {errorMsg = "Allele lengths do not match"}
        else if (!locusCheck) {errorMsg = "Gene loci error"}

        let gResults = document.getElementById("GenoResults");
        let pResults = document.getElementById("PhenoResults");
        gResults.innerHTML = `${errorMsg}, please try again`;
        pResults.innerHTML = "";
    }
}


function  CombineAlleles(p1, p2) {
    let singleAlleles = [];
    for(let i = 0; i < p1.length; i = i+2) {
        let temp = [];
        temp.push(p1[i] + p2[i]);
        temp.push(p1[i] + p2[i+1]);
        temp.push(p1[i+1] + p2[i]);
        temp.push(p1[i+1] + p2[i+1]);
        singleAlleles.push(temp);
    }

    return singleAlleles;
}


function F1Genotypes(singleAlleles) {
    let finalF1Arr = singleAlleles;
    let finalF1length = 0;

    // Each array in singleAlleles has all possible combos of each letter i.e. [[AA,Aa,aA,aa], [BB,Bb.bB,bb]]
    do {
        let i = 0;
        let currentArrLength = finalF1Arr.length - 1; // Length of array of arrays
        let f1Arr = [];

        while (i < currentArrLength) {
            let f1TempAllele = []; // array for storing paired alleles to push onto f1Arr
            let arr1 = finalF1Arr[i]; // ith array in finalF1arr to combo with (i+1)th  e.g. [AA,Aa,aA,aa]
            let arr2 = finalF1Arr[i+1]; // e.g. [BB,Bb,bB,bb]

            for (let j = 0; j < arr1.length; j++) {
                for (let k = 0; k < arr2.length; k++) {
                    f1TempAllele.push(arr1[j] + arr2[k]);
                }
            }

            f1Arr.push(f1TempAllele);
            i += 2;

            if (i == currentArrLength) {
                f1Arr.push(finalF1Arr[i]);
            }
        }

        finalF1Arr = f1Arr;
        finalF1length = finalF1Arr.length;
    } while (finalF1length > 1);

    return finalF1Arr;    
}


function DisplayResults(f1, dom) {
    let f1List = f1[0] //Turn F1 (arr of arr) into single arr for easier use
    let dataToDisplay = NormalizeGenotypeLettering(f1List); // Returns arr of allele types and total number of alleles
    let alleleTypes = dataToDisplay[0];
    let totalNumOfAlleles = dataToDisplay[1];

    let genotypeMap = new Map();
    let phenotypeMap = new Map();

    for (let i = 0; i < alleleTypes.length; i++) {
        let allele = alleleTypes[i];

        // Count number of different alleles (add to map)
        if (genotypeMap.has(allele)) {
            let newAmt = genotypeMap.get(allele) + 1;
            genotypeMap.set(allele, newAmt);
        }
        else {
            genotypeMap.set(allele, 1);
        }
    }


    if (dom == "INCOMPLETE") {
        phenotypeMap = PhenoIncompleteDominance(alleleTypes);
    }
    else if (dom == "CODOMINANCE") {
        phenotypeMap = PhenoCoDominance(alleleTypes);
    }
    else {
        phenotypeMap = PhenoCompleteDominance(alleleTypes);
    }

    let genotypeResults = "";
    genotypeMap.forEach((value, key) => {
        genotypeResults += `<p>${key}: ${value}/${totalNumOfAlleles}</p>`;
    })

    let phenotypeResults = "";
    phenotypeMap.forEach((value, key) => {
        phenotypeResults += `<p>${key}: ${value}/${totalNumOfAlleles}</p>`
    })

    let gResults = document.getElementById("GenoResults");
    gResults.innerHTML = genotypeResults;
    let pResults = document.getElementById("PhenoResults");
    pResults.innerHTML = phenotypeResults;

}

function NormalizeGenotypeLettering(f1) {
    let normalizedF1Arr = [];
    let totalNumOfAlleles = 0;
    for (let i = 0; i < f1.length; i++) {
        let allele = f1[i];
        let alleleTemp = "";
        for (let j = 0; j < allele.length; j += 2) {
            if (allele[j] == allele[j].toLowerCase() && allele[j+1] == allele[j+1].toUpperCase()) {
                alleleTemp += (allele[j+1] + allele[j]);
            }
            else {
                alleleTemp += (allele[j] + allele[j+1]);
            }
        }
        totalNumOfAlleles++;
        normalizedF1Arr.push(alleleTemp);
    }
    
    return [normalizedF1Arr, totalNumOfAlleles];
}


function PhenoCompleteDominance(alleleTypes) {

    console.log("COM");

    let phenotypeMap = new Map();

    for (let i = 0; i < alleleTypes.length; i++) {
        let allele = alleleTypes[i];

        // Count number of dominant/recessive phenotype (add to map)
        let phenoToAdd = "";
        for (let j = 0; j < allele.length; j = j+2) {
            phenoToAdd += allele[j];
        }
        if (phenotypeMap.has(phenoToAdd)) {
            let newAmt = phenotypeMap.get(phenoToAdd) + 1;
            phenotypeMap.set(phenoToAdd, newAmt);
        }
        else {
            phenotypeMap.set(phenoToAdd, 1);
        }

    }

    return phenotypeMap;
}

// TODO: Implement correctly
function PhenoIncompleteDominance(alleleTypes) {

    console.log("INC");

    let phenotypeMap = new Map();

    for (let i = 0; i < alleleTypes.length; i++) {
        let allele = alleleTypes[i];

        // Count number of dominant/recessive phenotype (add to map)
        let phenoToAdd = "";
        for (let j = 0; j < allele.length; j = j+2) {
            phenoToAdd += allele[j];
        }
        if (phenotypeMap.has(phenoToAdd)) {
            let newAmt = phenotypeMap.get(phenoToAdd) + 1;
            phenotypeMap.set(phenoToAdd, newAmt);
        }
        else {
            phenotypeMap.set(phenoToAdd, 1);
        }

    }

    return phenotypeMap;
}


// TODO: Implement correctly
function PhenoCoDominance(alleleTypes) {

    console.log("CO");

    let phenotypeMap = new Map();

    for (let i = 0; i < alleleTypes.length; i++) {
        let allele = alleleTypes[i];

        // Count number of dominant/recessive phenotype (add to map)
        let phenoToAdd = "";
        for (let j = 0; j < allele.length; j = j+2) {
            phenoToAdd += allele[j];
        }
        if (phenotypeMap.has(phenoToAdd)) {
            let newAmt = phenotypeMap.get(phenoToAdd) + 1;
            phenotypeMap.set(phenoToAdd, newAmt);
        }
        else {
            phenotypeMap.set(phenoToAdd, 1);
        }

    }

    return phenotypeMap;
}


function LocusCheck(p1, p2) {
    let ok = true;
    for (let i = 0; i < p1.length; i = i+2) {
        if (p1[i].toUpperCase() != p1[i+1].toUpperCase() || p1[i].toUpperCase() != p2[i].toUpperCase()) {
            ok = false;
        }
    }
    return ok;
}