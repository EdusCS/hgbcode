<!-- 
### Authors
<style>
.tablelines table{
        width: 120%;
        border: none!important;
        border-collapse: collapse;       
        border-spacing: 0;        
        }
.tablelines td{
    border: none!important;
    border-collapse: collapse;
}
</style>
<table class="tablelines">
  <tr >
    <td width="35%">Edward Cayllahua-Cahuina [1,2]</td>
    <td width="35%">Jean Cousty [1]</td>
    <td width="35%">Silvio Guimarães [3]</td>    
  </tr>
  <tr>
    <td>Yukiko Kenmochi [1]</td>
    <td>Guillermo Cámara-Chávez[4]</td>
    <td>Arnaldo de Albuquerque Araújo[2]</td>    
  </tr>
</table>
Hierarchical image segmentation provides region-oriented scale-spaces:
sets of image segmentations at different detail levels in which the
segmentations at finer levels are nested with respect to those at
coarser levels. This is the code for Hierarchical Graph Based Segmentation from a non Increasing Edge Observation Attribute <a href="https://link.springer.com/chapter/10.1007/978-3-030-14085-4_14" target="_blank"> [Cayllahua-et-al, 2019] </a>.  
-->
<div style="text-align:justify">
Hierarchical image segmentation provides a region-oriented scale-space, i.e., a set of image segmentations at different detail levels in which the segmentations at finer levels are nested with respect to those at coarser levels.  <a href="https://www.degruyter.com/downloadpdf/j/mathm.2017.2.issue-1/mathm-2017-0004/mathm-2017-0004.pdf" target="_blank"> <i>Guimarâes et al., 2017,</i></a>  proposed a hierarchical graph-based image segmentation (HGB) method based on the Felzenszwalb-Huttenlocher dissimilarity. This HGB method computes, for each edge of a graph, the minimum scale in a hierarchy at which two regions linked by this edge should merge according to the dissimilarity. In order to generalize this method, we first propose an algorithm to compute the intervals which contain all the observation scales at which the associated regions should merge. Then, following the current trend in mathematical morphology to study criteria which are not increasing on a hierarchy, we present various strategies to select a significant observation scale in these intervals. This is the code for Hierarchical Graph Based Segmentation from a non Increasing Edge Observation Attribute <a href="https://link.springer.com/chapter/10.1007/978-3-030-14085-4_14" target="_blank"> [Cayllahua et al., 2019] </a>.
</div>
<p>    </p>
<video width="{#}" height="200" controls>  
  <source src="https://cayllahe.github.io/hgbcode/assets/video/video2.mp4" type="video/mp4" />    
</video>
<p> </p>
<table style="width:100%" class="hgbtable" id="hgbtable">
  <tr>
    <th>Image</th>
    <th>Result of the original <a href="https://www.degruyter.com/downloadpdf/j/mathm.2017.2.issue-1/mathm-2017-0004/mathm-2017-0004.pdf" target="_blank" style="color:#1f487a">HGB method</a> (saliency map)</th>
    <th>Result of the HGB method with the newly proposed  upper P-rank selection strategy</th>
  </tr>
  <tr>
    <td rowspan="5"><img src="https://cayllahe.github.io/hgbcode/assets/Figures/2010_000666.png" width="255" height="166"></td>
    <td><img src="https://cayllahe.github.io/hgbcode/assets/Figures/MinSM.png" width="255" height="166"></td>
    <td><img src="https://cayllahe.github.io/hgbcode/assets/Figures/UpperPrankSM.png" width="255" height="166"></td>
  </tr>

  <tr>    
    <th>A segmentation obtained from Min-rule hierarchy (48 Regions)</th>
    <th>A segmentation obtained from Upper P-rank hierarchy (48 Regions)</th>
  </tr>
  <tr>    
    <td><img src="https://cayllahe.github.io/hgbcode/assets/Figures/Min_48_regions.png" width="255" height="166"></td>
    <td><img src="https://cayllahe.github.io/hgbcode/assets/Figures/prank_48_regions.png" width="255" height="166"></td>
  </tr>

  <tr>    
    <th>A segmentation obtained from Min-rule hierarchy (100 Regions)</th>
    <th>A segmentation obtained from Upper P-rank hierarchy (100 Regions)</th>
  </tr>
  <tr>    
    <td><img src="https://cayllahe.github.io/hgbcode/assets/Figures/Min_100_regions.png" width="255" height="166"></td>
    <td><img src="https://cayllahe.github.io/hgbcode/assets/Figures/prank_100_regions.png" width="255" height="166"></td>
  </tr>
  
</table>
<div style="text-align:justify;display: inline-block;">
Images used for tests come from PASCAL VOC 2010 and VOC 2012 dataset.  Click 
<a href="https://github.com/cayllahe/hgbcode/tree/master/docs/assets/files/segmentations.pdf" target="_blank">here</a> to see more hierarchical image segmentation results.  For a video showing segmentations obtained from HGB, click <a href="https://github.com/cayllahe/hgbcode/blob/master/video.mpg" target="_blank" style="display:inline;border:none, outline: none;">here<img src="https://cayllahe.github.io/hgbcode/assets/video/play.png" height="9" style="display:inline;vertical-align: middle;border:none, outline: none;">.</a>
<!-- <img src="https://cayllahe.github.io/hgbcode/assets/video/video.gif" height="8"> -->
</div>
### Get the code
Click <a href="https://github.com/cayllahe/hgbcode" target="_blank">here</a> to get the code.
### Build/Install
This code was compiled and executed in Linux. To compile use:
``` 
./compileHGB.sh
```
### Usage 
The program takes as input an image file in the format XXXX.ppm and produces as output a saliency map XXXX.pgm, which is the visualization of the hierarchy after performing the hierarchical graph based segmentation from a non increasing edge observation attribute of the input image. 

To execute the program: 

```
./hgbSegmentation.sh INPUT_IMAGE.ppm OUTPUT_SM.pgm OPTION PARAMETER AREASIMP
```
Where:  

**OPTION**:

```
1: Use Min: select minimum value on positive observation intervals
2: Use Max: select the last upper bound on negative intervals

3: Lower-length: On positive intervals, apply length threshold and min-rule
4: Upper-length: apply length threshold and max-rule

5: Lower-area: On positive intervals, apply area and  min-rule
6: Upper-Narea: On negative intervals, apply area and  max-rule

7: Lower-depth: On positive intervals, apply depth filter and min-rule
8: Upper-Ndepth: On negative intervals, apply depth filter and max-rule

9: Lower p-rank: On positive intervals, apply rank filter and  min-rule
10: Upper p-rank: On negative intervals, apply rank filter and  max-rule
```

**PARAMETER**: Refers to the  alpha or ranking parameter (threshold)

**AREASIMP**: Refers to the area simplification parameter. If no value is passed, then the value 0.004 is assumed. 

**Example**: 
```
./hgbSegmentation.sh Images/3063.ppm /tmp/salida.pgm 10 0.001 0.003 
```

### Citation 
Please cite as

```
@InProceedings{Cayllahuaetal2019,
author="Cayllahua-Cahuina, Edward
and Cousty, Jean
and Guimar{\~a}es, Silvio
and Kenmochi, Yukiko
and C{\'a}mara-Ch{\'a}vez, Guillermo
and de Albuquerque Ara{\'u}jo, Arnaldo",
title="A Study of Observation Scales Based on Felzenswalb-Huttenlocher Dissimilarity Measure for Hierarchical Segmentation",
booktitle="Discrete Geometry for Computer Imagery",
year="2019",
publisher="Springer International Publishing",
pages="167--179",
isbn="978-3-030-14085-4"
}
```
### Related articles to HGB
* Cayllahua-Cahuina, E., Cousty, J., Guimarães, S.J.F.,  Kenmochi, Y., Cámara-Chávez, G. & Araújo, A. de A. <a href="https://link.springer.com/chapter/10.1007/978-3-030-14085-4_14" target="_blank" style="color:#1f487a;font-weight: bold;"> A study of observation scales based on Felzenswalb-Huttenlocher dissimilarity measure for hierarchical segmentation</a>. Proceedings of the 21st International Conference on Discrete Geometry for Computer Imagery, DGCI, Paris, France, Lecture Notes in Computer Science, Springer,  DOI 10.1007/978-3-030-14085-4_14, vol. 11414, 2019, pp 167-179.

* Cayllahua-Cahuina, E., Cousty, J., Guimarães, S.J.F.,  Kenmochi, Y., Cámara-Chávez, G. & Araújo, A. de A.  <a href="https://repositorio.ufop.br/bitstream/123456789/11338/1/ARTIGO_EfficientAlgorithmsHierarchical.pdf" target="_blank" style="color:#1f487a;font-weight: bold;"> Efficient algorithms for hierarchical graph-based segmentation relying on the Felzenszwalb-Huttenlocher dissimilarity </a>. International Journal of Pattern Recognition and Artificial Intelligence,  DOI 10.1142/S0218001419400081, vol. 33, no. 11, 2019, pp 1-27.

* Cayllahua-Cahuina, E., Cousty, J., Kenmochi, Y., Araújo, A. de A. & Cámara-Chávez, G. <a href="https://hal-upec-upem.archives-ouvertes.fr/hal-01710920/document" target="_blank" style="color:#1f487a;font-weight: bold;"> Algorithms for hierarchical segmentation based on the Felzenszwalb-Huttenlocher dissimilarity </a>. Proceedings of the International Conference on Pattern Recognition and Artificial Intelligence, ICPRAI, Montréal, Canada, ISBN no. 1 895193 06 0, 2018, pp 108-113.

* Guimarães, S., Kenmochi, Y., Cousty, J., Patrocinio N.
 & Najman L. <a href="https://www.degruyter.com/downloadpdf/j/mathm.2017.2.issue-1/mathm-2017-0004/mathm-2017-0004.pdf" target="_blank" style="color:#1f487a;font-weight: bold;">Hierarchizing graph-based image segmentation algorithms relying on region dissimilarity </a>. Mathematical Morphology - Theory and Applications, 2(1),  DOI 10.1515/mathm-2017-0004, 2017, pp. 55-75.

* Cousty, J., Najman L., Kenmochi, Y., & Guimarães, S. <a href="https://hal.archives-ouvertes.fr/hal-01344727v2/document" target="_blank" style="color:#1f487a;font-weight: bold;"> Hierarchical segmentations with graphs: quasi-flat zones, minimum spanning trees, and saliency maps </a>. Journal of Mathematical Imaging and Vision. DOI 10.1007/s10851-017-0768-7, vol. 60, no. 4, 2018, pp 479-502.

### Licence information
This software is governed by the CeCILL license under French law and abiding by the rules of distribution of free software. You can use, modify and/ or redistribute the software under the terms of the CeCILL license as circulated by CEA, CNRS and INRIA at the following <a href="https://cecill.info/licences/Licence_CeCILL_V2.1-en.html" target="_blank"> URL </a>.


### Institutions
<style>
.tablelines table{
        width: 120%;
        border: none!important;
        border-collapse: collapse;       
        border-spacing: 0;        
        }
.tablelines td{
    border: none!important;
    border-collapse: collapse;
}
</style>
<table class="tablelines">  
    <tr>
      <td colspan="3">        
    Edward Cayllahua-Cahuina [1,2], Jean Cousty [1], Silvio Guimarães [3], 
    Yukiko Kenmochi [1], Guillermo Cámara-Chávez[4], & Arnaldo de Albuquerque Araújo [1,2]
      </td>
    </tr>
    <tr>
    <td colspan="3"> 
        [1] Université Paris-Est, LIGM (UMR 8049), CNRS, ENPC, ESIEE Paris, UPEM <br>
        [2] Universidade Federal de Minas Gerais, DCC - NPDI<br>
        [3] Pontifícia Universidade Católica De Minas Gerais - VIPLAB <br>
        [4] Universidade Federal de Ouro Preto - DECOM
    </td>    
    </tr>
    <tr> 
    <td colspan="3" style="text-align: center;padding-left:20px;padding-right:20px;">
      <img src="https://cayllahe.github.io/hgbcode/assets/logos/upem.png" width="160" height="40">
        <img src="https://cayllahe.github.io/hgbcode/assets/logos/esiee.png" width="120" height="45">
        <img src="https://cayllahe.github.io/hgbcode/assets/logos/ligm.png" width="100" height="100">
        <br>
        <img src="https://cayllahe.github.io/hgbcode/assets/logos/ufmg.png" width="130" height="50">
        <img src="https://cayllahe.github.io/hgbcode/assets/logos/dcc.png" width="120" height="60">
        <img src="https://cayllahe.github.io/hgbcode/assets/logos/npdi.png" width="80" height="140"><br>
        <img src="https://cayllahe.github.io/hgbcode/assets/logos/puc.png" width="120" height="100">
        <img src="https://cayllahe.github.io/hgbcode/assets/logos/ufop.jpg" width="70" height="140"><br>
        <img src="https://cayllahe.github.io/hgbcode/assets/logos/capescofecub.jpg" width="140" height="50">
        <img src="https://cayllahe.github.io/hgbcode/assets/logos/cnpq.png" width="90" height="40">
        <img src="https://cayllahe.github.io/hgbcode/assets/logos/concytec.png" width="140" height="50">
        </td>   
    </tr>
</table>



