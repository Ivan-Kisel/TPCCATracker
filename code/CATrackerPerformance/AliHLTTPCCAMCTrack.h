/*
 * This file is part of TPCCATracker package
 * Copyright (C) 2007-2020 FIAS Frankfurt Institute for Advanced Studies
 *               2007-2020 Goethe University of Frankfurt
 *               2007-2020 Ivan Kisel <I.Kisel@compeng.uni-frankfurt.de>
 *               2007-2019 Sergey Gorbunov
 *               2007-2019 Maksym Zyzak
 *               2007-2014 Igor Kulakov
 *               2014-2020 Grigory Kozlov
 *
 * TPCCATracker is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * TPCCATracker is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef ALIHLTTPCCAMCTRACK_H
#define ALIHLTTPCCAMCTRACK_H


#include <iostream>
using std::ostream;
using std::istream;

class TParticle;


/**
 * @class AliHLTTPCCAMCTrack
 * store MC track information for AliHLTTPCCAPerformance
 */
class AliHLTTPCCAMCTrack
{
 public:

  AliHLTTPCCAMCTrack();
#ifndef HLTCA_STANDALONE
  AliHLTTPCCAMCTrack( const TParticle *part );
#endif
  
  // void SetTPCPar( float X, float Y, float Z, float Px, float Py, float Pz );

  int MotherId()       const { return fMotherId; }
  int    PDG()         const { return fPDG;}
  float Par( int i )    const { return fPar[i]; }
  float TPCPar( int i ) const { return fTPCPar[i]; }

  float X()           const { return fPar[0]; }
  float Y()           const { return fPar[1]; }
  float Z()           const { return fPar[2]; }
  float Px()          const { return fPar[3]*fP; }
  float Py()          const { return fPar[4]*fP; }
  float Pz()          const { return fPar[5]*fP; }
  float P()           const { return fP; }
  float Pt()          const { return fPt; }
  const float *Par()            const { return fPar; }
  const float *TPCPar()         const { return fTPCPar; }

  int     NHits()          const { return fNHits;}
  int     NMCPoints()      const { return fNMCPoints;}
  int     FirstMCPointID() const { return fFirstMCPointID;}
  int     NReconstructed() const { return fNReconstructed; }
  int     Set()            const { return fSet; }
  int     NTurns()         const { return fNTurns; }

  int     NMCRows()         const { return fNMCRows; }

  void SetMotherId( int v )          { fMotherId = v; }
  void SetP ( float v )          { fP = v; }
  void SetPt( float v )          { fPt = v; }
  void SetPDG( int v )         { fPDG = v; }
  void SetPar( int i, float v )             { fPar[i] = v; }
  void SetTPCPar( int i, float v )          { fTPCPar[i] = v; }
  void SetNHits( int v )         { fNHits = v; }
  void SetNMCPoints( int v )      { fNMCPoints = v; }
  void SetFirstMCPointID( int v ) { fFirstMCPointID = v;}
  void SetNReconstructed( int v ) { fNReconstructed = v; }
  void SetSet( int v )           { fSet = v; }
  void SetNTurns( int v )        { fNTurns = v; }

  void SetNMCRows( int v )        { fNMCRows = v; }

  // ---
  void SetSet1( int v )           { tSet1 = v; }
  int     Set1()            const { return tSet1; }
  void SetSet30( int v )           { tSet30 = v; }
  int     Set30()            const { return tSet30; }
  // ---

  friend ostream& operator<<(ostream& out, const AliHLTTPCCAMCTrack &a);
  friend istream& operator>>(istream& in, AliHLTTPCCAMCTrack &a);

 protected:

  int    fMotherId;      //* index of mother track in tracks array. -1 for primary tracks. -2 if a mother track is not in the acceptance
  int    fPDG;           //* particle pdg code
  float fPar[7];         //* x,y,z,ex,ey,ez,q/p
  float fTPCPar[7];      //* x,y,z,ex,ey,ez,q/p at TPC entrance (x=y=0 means no information)
  float fP, fPt;         //* momentum and transverse momentum
  int    fNHits;          //* N TPC clusters
  int    fNMCPoints;      //* N MC points
  int    fFirstMCPointID; //* id of the first MC point in the points array
  int    fNReconstructed; //* how many times is reconstructed
  int    fSet;            //* set of tracks 0-OutSet, 1-ExtraSet, 2-RefSet
  int    fNTurns;         //* N of turns in the current sector

  int    fNMCRows; // N rows with MC Points. Calculated after reading all MC info.

  int tSet1;
  int tSet30;
};

#endif
